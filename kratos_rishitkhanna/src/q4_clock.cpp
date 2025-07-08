#include <algorithm>
#include <memory>
#include <string>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("clock_publisher"),seconds(0), minutes(0),hours(0)
  {
      publisher_ = this->create_publisher<std_msgs::msg::String>("clock", 20);


    auto topic_callback1 =
      [this](std_msgs::msg::Int32::UniquePtr msg) -> void {
        seconds=msg->data;
      };
    auto topic_callback2 =
      [this](std_msgs::msg::Int32::UniquePtr msg) -> void {
        minutes=msg->data;
      };
    auto topic_callback3 =
      [this](std_msgs::msg::Int32::UniquePtr msg) -> void {
        hours=msg->data;
      };

      auto topic_callback4 =
      [this]() -> void {
        auto message = std_msgs::msg::String();
        message.data =std::to_string(hours) + ":" + std::to_string(minutes) + ":" +std::to_string(seconds);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        this->publisher_->publish(message);
      };
    subscription_s =
      this->create_subscription<std_msgs::msg::Int32>("second", 10, topic_callback1);
    subscription_min =
      this->create_subscription<std_msgs::msg::Int32>("minute", 10, topic_callback2);
    subscription_hr =
      this->create_subscription<std_msgs::msg::Int32>("hour", 10, topic_callback3);

    timer_=this->create_wall_timer(1000ms, topic_callback4);
  }

private:
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_s;
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_min;
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_hr;

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

  size_t seconds,minutes,hours;

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
