#include "ros/ros.h"
#include "std_msgs/Int8.h"

class pubInt8 {
public:
    pubInt8 (ros::NodeHandle& nh) {
        chatter_pub = nh.advertise<std_msgs::Int8>("chatter", 1000);
    }

    void pub() {
        int count = 0;
        ros::Rate loop_rate(10);
        while (ros::ok()) {
            std_msgs::Int8 msg;
            msg.data = count;
            ROS_INFO("%d", msg.data);

            chatter_pub.publish(msg);
            ros::spinOnce();

            loop_rate.sleep();
            ++count;
        }
    }

private:
    ros::Publisher chatter_pub;
};

int main(int argc, char **argv) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle n;

    pubInt8 pb8(n);
    pb8.pub();

    return 0;
}