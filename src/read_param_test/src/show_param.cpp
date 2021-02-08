#include "ros/ros.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "show_param");
    ros::NodeHandle nh;

    double noise;
    if (nh.getParam("noise", noise)) {
        ROS_INFO("noise is %f", noise);
    } else {
        ROS_INFO("didn't find parameter noise");
    }

    std::string string_var;
    if (nh.getParam("string_var", string_var)) {
        ROS_INFO("string_var: %s", string_var.c_str());
    } else {
        ROS_WARN("No string_var name message");
    }

    std::vector<int> a_list;
    if (nh.getParam("a_list",a_list)) {
        ROS_INFO("get a_list");
    } else {
        ROS_WARN("didn't find a_list");
    }

    std::vector<int> vector_var;
    if (nh.getParam("vector_var",vector_var)) {
        ROS_INFO("got vector");
    } else {
        ROS_WARN("didn't find vector");
    }

    double a = 0;
    int    b = 0;
    if (nh.getParam("control/a", a) && nh.getParam("control/b", b)) {
        ROS_INFO("a: %f, b: %d", a, b);
    } else {
        ROS_WARN("didn't find a and b");
    }
    
    while (ros::ok()) {
        ROS_INFO("param is %f, %s, %f, %d ", noise, string_var.c_str(), a, b);
        usleep(2000000);
    }
    
    
}