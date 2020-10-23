//
// Created by pohzhiee on 22/10/20.
//

#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <Eigen/Core>
#include <array>
#include <fstream>
#include <iomanip>
#include <nlohmann/json.hpp>

using namespace std::chrono;

struct Data{
    long nrows;
    long ncols;
    std::vector<double> data;
    uint64_t timestamp;
};

std::mutex m;
std::condition_variable cv;
Data bufferData;

std::vector<uint64_t> timeDiffList{};
std::atomic<uint64_t> count{0};
std::atomic<bool> doneFlag{false};

void PublisherThread(){
    while (true) {
        //  Write three messages, each with an envelope and content
        if(doneFlag)
            return;
        Eigen::MatrixXd someData = Eigen::MatrixXd::Identity(20, 20);

        // include serialization time
        uint64_t time = duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
        auto data = Data{someData.rows(), someData.cols(), {someData.data(), someData.data()+someData.count()}, time};
        data.timestamp = time;
        {
            std::lock_guard<std::mutex> lk(m);
            bufferData = data;
        }
        cv.notify_all();
//        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

void SubscriberThread(){

    while (true){
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk);
        // prevent compiler from optimising deserialization
        volatile Eigen::MatrixXd myMat = Eigen::Map<const Eigen::MatrixXd>(&bufferData.data[0], bufferData.nrows, bufferData.ncols);

        auto now = high_resolution_clock::now();
        lk.unlock();
        auto timeDiff = now.time_since_epoch().count() - bufferData.timestamp;
        if(count < 10000)
        {
            timeDiffList.emplace_back(timeDiff);
            count++;
        }
        else if(count == 10000){
            nlohmann::json j;
            j = timeDiffList;

// write prettified JSON to another file
            std::ofstream o("manual_data_nodelay.json");
            o << std::setw(4) << j << std::endl;
            std::cout << "Data saved to manual_data_nodelay.json" << std::endl;
            doneFlag = true;
            return;
        }
//        std::cout << "Time diff: " << timeDiff << std::endl;
//        std::cout << "Received:\n" << myMat << std::endl;
    }
}


int main(){
    timeDiffList.reserve(50000);
    auto thread1 = std::async(std::launch::async, PublisherThread);
    auto thread2 = std::async(std::launch::async, SubscriberThread);


    thread1.wait();
    thread2.wait();
    std::cout << "HELLO WORLD" << std::endl;
}
