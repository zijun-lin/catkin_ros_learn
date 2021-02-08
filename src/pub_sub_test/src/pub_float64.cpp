#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Float64>("chatter", 1000);
  ros::Rate loop_rate(10);

  double count = 0;
  while (ros::ok()) {
    std_msgs::Float64 msg;
    msg.data = count;
    ROS_INFO("hellow %f", msg.data);

    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    count += 0.1;
  }

  return 0;
}