#include <future>
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>

#include <Eigen/Core>
#include "zmq.hpp"
#include "zmq_addon.hpp"

#include <nlohmann/json.hpp>


std::vector<uint64_t> timeDiffList{};
std::atomic<uint64_t> count{0};
std::atomic<bool> doneFlag{false};

using namespace std::chrono;
using namespace std::chrono_literals;
void PublisherThread(zmq::context_t *ctx) {
    //  Prepare publisher
    zmq::socket_t publisher(*ctx, zmq::socket_type::pub);
    publisher.bind("inproc://123");

    // Give the subscribers a chance to connect, so they don't lose any messages
    std::this_thread::sleep_for(std::chrono::milliseconds(20));

    Eigen::MatrixXd someData = Eigen::MatrixXd::Identity(20, 20);
    auto time = high_resolution_clock::now().time_since_epoch().count();
    std::pair<Eigen::MatrixXd, uint64_t> someDataCopy = {someData, time};
    while (true) {
        if(doneFlag)
            return;
        someDataCopy.second = high_resolution_clock::now().time_since_epoch().count();
        someDataCopy.first = someData;
        publisher.send(zmq::str_buffer("T"), zmq::send_flags::sndmore);
        publisher.send(zmq::buffer((void*)&someDataCopy, sizeof(std::pair<Eigen::MatrixXd, uint64_t>)));
        std::this_thread::sleep_for(std::chrono::microseconds (2000));
    }
}

void SubscriberThread1(zmq::context_t *ctx) {
    //  Prepare subscriber
    zmq::socket_t subscriber(*ctx, zmq::socket_type::sub);
    subscriber.connect("inproc://123");

    subscriber.set(zmq::sockopt::subscribe, "T");
    while (true) {
        std::vector<zmq::message_t> recv_msgs;
        zmq::recv_result_t result = zmq::recv_multipart(subscriber, std::back_inserter(recv_msgs));
        assert(result && "recv failed");
        auto topic = recv_msgs[0].to_string_view();
        auto dataPtr = reinterpret_cast<std::pair<Eigen::MatrixXd, uint64_t>*>(recv_msgs[1].data());
        if(dataPtr != nullptr){

            volatile Eigen::MatrixXd myMat = dataPtr->first; // prevent compiler from optimising deserialization
            auto timeDiff = high_resolution_clock::now().time_since_epoch().count() - (*dataPtr).second;

            if(count < 10000){
                timeDiffList.emplace_back(timeDiff);
                count++;
            }
            else if(count == 10000){
                nlohmann::json j;
                j = timeDiffList;

                std::ofstream o("zmq_data.json");
                o << std::setw(4) << j << std::endl;
                std::cout << "Data saved to zmq_data.json" << std::endl;
                doneFlag = true;
                return;
            }
        }
        else{
            std::cout << "nullptr" << std::endl;
        }
        recv_msgs.clear();
    }
}


int main() {
    /*
     * No I/O threads are involved in passing messages using the inproc transport.
     * Therefore, if you are using a ØMQ context for in-process messaging only you
     * can initialise the context with zero I/O threads.
     *
     * Source: http://api.zeromq.org/4-3:zmq-inproc
     */
    zmq::context_t ctx(0);

    auto thread1 = std::async(std::launch::async, PublisherThread, &ctx);

    // Give the publisher a chance to bind, since inproc requires it
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    auto thread2 = std::async(std::launch::async, SubscriberThread1, &ctx);
    thread1.wait();
    thread2.wait();

    /*
     * Output:
     *   An infinite loop of a mix of:
     *     Thread2: [A] Message in A envelope
     *     Thread2: [B] Message in B envelope
     *     Thread3: [A] Message in A envelope
     *     Thread3: [B] Message in B envelope
     *     Thread3: [C] Message in C envelope
     */
}

//#include <iostream>
//#include <zmq_addon.hpp>
//#include <Eigen/Core>
//
//int main()
//{
//    zmq::context_t ctx;
//    zmq::socket_t sock1(ctx, zmq::socket_type::pair);
//    zmq::socket_t sock2(ctx, zmq::socket_type::pair);
//    sock1.bind("inproc://test");
//    sock2.connect("inproc://test");
//
//    Eigen::MatrixXd someData = Eigen::MatrixXd::Identity(20, 20);
//    std::array<zmq::const_buffer, 3> send_msgs = {
//            zmq::str_buffer("foo"),
//            zmq::str_buffer("bar!"),
//            zmq::buffer(&someData, sizeof(Eigen::MatrixXd))
//    };
//    if (!zmq::send_multipart(sock1, send_msgs))
//        return 1;
//
//    std::vector<zmq::message_t> recv_msgs;
//    const auto ret = zmq::recv_multipart(
//            sock2, std::back_inserter(recv_msgs));
//    if (!ret)
//        return 1;
//    std::cout << "Got " << *ret
//              << " messages" << std::endl;
//    auto ptr = reinterpret_cast<Eigen::MatrixXd*>(recv_msgs[2].data());
//    if(ptr == nullptr){
//        std::cout << "Nullptr" << std::endl;
//    }
//    else{
//        std::cout << *ptr << std::endl;
//    }
//    return 0;
//}