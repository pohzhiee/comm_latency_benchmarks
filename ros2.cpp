
#include <chrono>
#include <vector>
#include <fstream>
#include <iomanip>
#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/u_int64.hpp"
#include <nlohmann/json.hpp>

std::vector<uint64_t> timeDiffList{};
std::atomic<uint64_t> count{0};

using namespace std::chrono;
// Create a Listener class that subclasses the generic rclcpp::Node base class.
// The main function below will instantiate the class as a ROS node.
class SomeNode : public rclcpp::Node
{
public:
    SomeNode()
            : Node("someNode")
    {
        // Create a callback function for when messages are received.
        // Variations of this function also exist using, for example UniquePtr for zero-copy transport.
        setvbuf(stdout, NULL, _IONBF, BUFSIZ);
        auto callback =
                [this](const std_msgs::msg::UInt64::SharedPtr msg) -> void
                {
                    auto now = high_resolution_clock::now();
                    microseconds dur(msg->data);
                    std::chrono::time_point<std::chrono::high_resolution_clock> dt(dur);
                    auto timeDiff = std::chrono::duration_cast<std::chrono::nanoseconds>(now - dt).count();
                    if(count < 10000){
                        timeDiffList.emplace_back(timeDiff);
                        count++;
                    }
                    else if(count == 10000){
                        nlohmann::json j;
                        j = timeDiffList;

                        std::ofstream o("ros2_data.json");
                        o << std::setw(4) << j << std::endl;
                        std::cout << "Data saved to ros2_data.json" << std::endl;
                        count++;
                        return;
                    }
                };
        auto publish_message =
                [this]() -> void
                {
                    pubMsg_ = std::make_unique<std_msgs::msg::UInt64>();
                    auto now = high_resolution_clock::now().time_since_epoch();
                    pubMsg_->data = duration_cast<microseconds>(now).count();
                    // Put the message into a queue to be processed by the middleware.
                    // This call is non-blocking.
                    pub_->publish(std::move(pubMsg_));
                };
        // Create a publisher with a custom Quality of Service profile.
        rclcpp::QoS qos(rclcpp::KeepLast(100));
        qos.best_effort();
        pub_ = this->create_publisher<std_msgs::msg::UInt64>("chatter2", qos);

        // Use a timer to schedule periodic message publishing.
        timer_ = this->create_wall_timer(2ms, publish_message);
        // Create a subscription to the topic which can be matched with one or more compatible ROS
        // publishers.
        // Note that not all publishers on the same topic with the same type will be compatible:
        // they must have compatible Quality of Service policies.
        sub_ = create_subscription<std_msgs::msg::UInt64>("chatter2", qos, callback);
    }

private:
    std::array<uint64_t, 100> timeBuffer_{};
    std::atomic<uint32_t> index_{0};
    rclcpp::Subscription<std_msgs::msg::UInt64>::SharedPtr sub_;
    rclcpp::Publisher<std_msgs::msg::UInt64>::SharedPtr pub_;
    std::unique_ptr<std_msgs::msg::UInt64> pubMsg_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    timeDiffList.reserve(10000);
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SomeNode>());
    rclcpp::shutdown();
    return 0;
}
