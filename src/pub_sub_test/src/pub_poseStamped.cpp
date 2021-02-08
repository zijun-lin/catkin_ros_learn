#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include <cmath>

int main(int argc, char **argv) {
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<geometry_msgs::PoseStamped>("chatter", 1000);
  ros::Rate loop_rate(10);

  // generate pose by ourselves.
  double pos_x, pos_y, pos_z;
  double ori_x, ori_y, ori_z, ori_w;
  // We just make the robot has fixed orientation. Normally 
  // quaternion needs to be normalized, which means x^2 + y^2 + z^2 +w^2 = 1
  double fixed_ori = 0.1;
  ori_x = fixed_ori;
  ori_y = fixed_ori;
  ori_z = fixed_ori;
  ori_w = sqrt(1.0 - 3.0 * fixed_ori * fixed_ori);

  double count = 0.0;
  while (ros::ok()) {
    // We just make the position x,y,z all the same. The X,Y,Z increase linearly
    pos_x = count;
    pos_y = count;
    pos_z = count;
    geometry_msgs::PoseStamped msg;

    // assign value to poseStamped
    ros::Time current_time = ros::Time::now();
    msg.header.stamp = current_time;
    // Then assign value to "pose", which has member position and orientation
    msg.pose.position.x = pos_x;
    msg.pose.position.y = pos_y;
    msg.pose.position.z = pos_z;
    msg.pose.orientation.x = ori_x;
    msg.pose.orientation.y = ori_y;
    msg.pose.orientation.z = ori_z;
    msg.pose.orientation.w = ori_w;

    ROS_INFO("we publish the robot's position and orientaion");
    ROS_INFO("the position(x,y,z) is %f , %f, %f", msg.pose.position.x, msg.pose.position.y, msg.pose.position.z);
    ROS_INFO("the orientation(x,y,z,w) is %f , %f, %f, %f", msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w);
    ROS_INFO("the time we get the pose is %f",  msg.header.stamp.sec + 1e-9*msg.header.stamp.nsec);

    std::cout<<"\n \n"<<std::endl;

    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  return 0;
}