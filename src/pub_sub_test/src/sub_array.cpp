#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"

void chatterCallback(const std_msgs::Float64MultiArray::ConstPtr& msg) {
  ROS_INFO("I heard: [%f, %f]", msg->data, msg->data[4]);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  ros::spin();

  return 0;
}