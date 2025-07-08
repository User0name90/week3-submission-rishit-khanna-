#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minute_publisher"), count_(0),pmsg(0)
  {
      publisher_ = this->create_publisher<std_msgs::msg::Int32>("minute", 10);
    auto topic_callback =
      [this](std_msgs::msg::Int32::UniquePtr msg) -> void {
        RCLCPP_INFO(this->get_logger(), "I heard: '%d's", msg->data);
        if(msg->data==0 && pmsg==59)
        {
            count_++;
        }
        if(count_==60) count_=0;
        pmsg=msg->data;
        msg->data=count_;
        RCLCPP_INFO(this->get_logger(), "Publishing: '%d'min", msg->data);
        this->publisher_->publish(*msg);
      };
    subscription_ =
      this->create_subscription<std_msgs::msg::Int32>("second", 10, topic_callback);

  }

private:
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
   size_t count_;
   size_t pmsg;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
