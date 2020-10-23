cmake_minimum_required(VERSION 3.17)
project(latency_bench)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_ROS2_BENCH "Build ROS2 latency benchmark, requires ROS2" ON)
option(BUILD_CPPZMQ_BENCH "Build ZeroMQ latency benchmark, requires cppzmq" ON)
option(BUILD_ECAL_BENCH "Build eCAL latency benchmark, requires eCAL" ON)

find_package(nlohmann_json 3.7 REQUIRED)
find_package(Eigen3 REQUIRED)

find_package( Threads REQUIRED )
add_executable(manual manual.cpp)
target_link_libraries(manual ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_DL_LIBS} nlohmann_json::nlohmann_json)

if(BUILD_CPPZMQ_BENCH)
    find_package(cppzmq 4.7.1 REQUIRED)
    add_executable(cppzmq_bench cppzmq.cpp)
    target_link_libraries(cppzmq_bench cppzmq Eigen3::Eigen nlohmann_json::nlohmann_json)
endif()

if(BUILD_ROS2_BENCH)
    find_package(ament_cmake REQUIRED)
    find_package(rclcpp REQUIRED)

    add_executable(ros2_bench ros2.cpp)
    ament_target_dependencies(ros2_bench rclcpp std_msgs)
endif()

if(BUILD_ECAL_BENCH)
    find_package(eCAL REQUIRED)
    find_package(Protobuf REQUIRED)
    FILE(TO_NATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/protobuf PROTOMODEL_PATH)
    FILE(TO_NATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/protobuf PROTOBINDING_PATH)

    FILE(GLOB DATAMODEL_PROTOS "${PROTOMODEL_PATH}/*.proto")

    FOREACH(proto ${DATAMODEL_PROTOS})
        FILE(TO_NATIVE_PATH ${proto} proto_native)
        EXECUTE_PROCESS(COMMAND ${PROTOBUF_PROTOC_EXECUTABLE} --proto_path=${PROTOMODEL_PATH} --cpp_out=${PROTOBINDING_PATH} ${proto_native}
                RESULT_VARIABLE rv)
        # Optional, but that can show the user if something have gone wrong with the proto generation
        IF(${rv})
            MESSAGE("Generation of data model returned ${rv} for proto ${proto_native}")
        ENDIF()
    ENDFOREACH(proto)

    FILE(GLOB PROTO_HDRS "${PROTOBINDING_PATH}/*.h")
    FILE(GLOB PROTO_SRCS "${PROTOBINDING_PATH}/*.cc")

    add_executable(ecal_bench ecal.cpp ${PROTO_SRCS} ${PROTO_HDRS})

    target_link_libraries(ecal_bench
            eCAL::core
            protobuf::libprotobuf
            )
endif()

