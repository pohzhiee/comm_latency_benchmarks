
/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

#include <ecal/ecal.h>
#include <ecal/msg/protobuf/publisher.h>

#include <iostream>
#include <chrono>
#include <numeric>
#include <fstream>
#include <iomanip>
#include <Eigen/Core>

#include "generated/bench1.pb.h"


#include <ecal/msg/protobuf/subscriber.h>
#include <nlohmann/json.hpp>

std::vector<uint64_t> timeDiffList{};
std::atomic<uint64_t> count{0};
uint64_t maxCount = 10000;

void OnPerson(const char* topic_name_, const pb::Bench1::Bench1& person_, const long long time_, const long long clock_)
{
    auto now = std::chrono::high_resolution_clock::now();
    const auto map1 = Eigen::Map<const Eigen::MatrixXd>(&person_.data()[0], person_.nrows(), person_.ncols());
    auto mat1 = Eigen::MatrixXd(person_.nrows(), person_.ncols());
    mat1 << map1;

    std::chrono::microseconds dur(person_.time());
    std::chrono::time_point<std::chrono::high_resolution_clock> dt(dur);
    uint64_t timeDiff = std::chrono::duration_cast<std::chrono::nanoseconds>(now - dt).count();
//     std::cout << "Time diff: " << std::chrono::duration_cast<std::chrono::microseconds>(timeDiff).count() << "us" << std::endl;
    if(count < maxCount){
        timeDiffList.emplace_back(timeDiff);
        count++;
    }
    else if(count == maxCount){
        nlohmann::json j;
        j = timeDiffList;

        std::ofstream o("ecal_data.json");
        o << std::setw(4) << j << std::endl;
        std::cout << "Data saved to ecal_data.json" << std::endl;
        count++;
        return;
    }
}

int main(int argc, char **argv) {
    using namespace std::chrono;
    // initialize eCAL API
    eCAL::Initialize(argc, argv, "bench1 publisher");

    // set process state
    eCAL::Process::SetState(proc_sev_healthy, proc_sev_level1, "I feel good !");
    eCAL::Util::EnableLoopback(true);
    eCAL::protobuf::CSubscriber<pb::Bench1::Bench1> sub("bench1");

    // add receive callback function (_1 = topic_name, _2 = msg, _3 = time, _4 = clock, _5 = id)
    auto callback = std::bind(OnPerson, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
    sub.AddReceiveCallback(callback);
    // create a publisher (topic name "person")
    eCAL::protobuf::CPublisher<pb::Bench1::Bench1> pub("bench1");


    // generate a class instance of Person
    pb::Bench1::Bench1 bench1;

    unsigned countA = 0;
    static bool created = false;
    // enter main loop
    auto startTime = std::chrono::high_resolution_clock::now();
    while (eCAL::Ok()) {
        ++countA;
        Eigen::MatrixXd asdf = Eigen::MatrixXd::Identity(18, 18) * count;
        bench1.set_ncols(asdf.cols());
        bench1.set_nrows(asdf.rows());
        std::vector<double> someData{};
//        someData.reserve(2500);
//        for (unsigned i = 0; i < 2500; i++) {
//            someData.push_back(0.1);
//        }
        *bench1.mutable_data() = {asdf.data(), asdf.data()+ asdf.cols() * asdf.rows()};

        // send the person object
        auto timeNow = std::chrono::high_resolution_clock::now();
        auto timeVal = std::chrono::duration_cast<std::chrono::microseconds>(timeNow.time_since_epoch()).count();
        bench1.set_time(timeVal);
        pub.Send(bench1);

        eCAL::Process::SleepMS(2);
    }

    // finalize eCAL API
    eCAL::Finalize();

    return (0);
}
