#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses a fancy C++11 lambda
* function to shorten the callback syntax, at the expense of making the
* code somewhat more difficult to understand at first glance. */

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("second_publisher"), count_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::Int32>("second", 10);
    auto timer_callback =
      [this]() -> void {
        auto message = std_msgs::msg::Int32();
        message.data =count_++;
        RCLCPP_INFO(this->get_logger(), "Publishing: '%d's", message.data);
        this->publisher_->publish(message);
        if(count_==60) count_=0;
      };
    timer_ = this->create_wall_timer(1000ms, timer_callback);
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
