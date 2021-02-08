#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"
#include <vector>

int main(int argc, char **argv) {
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Float64MultiArray>("chatter", 1000);
  ros::Rate loop_rate(10);

  std::vector<double> array_test = {1.1, 2.2, 3.3, 4.4, 5.5};
  while (ros::ok()) {
    std_msgs::Float64MultiArray msg;
    msg.data = array_test;
    ROS_INFO("%f, %f, %f", msg.data, msg.data[0], msg.data[1]);

    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}