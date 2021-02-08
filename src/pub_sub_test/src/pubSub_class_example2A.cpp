#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <unistd.h>

class tl1 {
public:
    tl1();
    void registerNodeHandle(ros::NodeHandle &_nh);
    void registerPubSub();
    void iniPub();
    void fCallback(const std_msgs::Float64::ConstPtr &msg);

private:
    ros::Publisher  pub_f64;
    ros::Subscriber sub_f64;
    ros::NodeHandle nh;
};

tl1::tl1() {};

void tl1::registerNodeHandle(ros::NodeHandle &_nh) {
    nh = _nh;
};

void tl1::registerPubSub() {
    pub_f64 = nh.advertise<std_msgs::Float64>("chatter1to2", 1000);
    sub_f64 = nh.subscribe("chatter2to1", 1000, &tl1::fCallback, this);
};

void tl1::fCallback(const std_msgs::Float64::ConstPtr &msg) {
    std::cout << "talker_listener1 heard " << msg->data << std::endl;
    std_msgs::Float64 pubData;
    pubData.data = msg->data + 1;

    ros::Rate sr(10);
    pub_f64.publish(pubData);
    sr.sleep();
};

void tl1::iniPub() {
    std::cout << "publish the first data " << std::endl;
    std_msgs::Float64 pubData;

    pubData.data = 1;

    usleep(5000000);  // 不宜过小，不然打印不出来
    pub_f64.publish(pubData);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "talker_listener1");
    ros::NodeHandle nh;
    tl1 pubSub1;

    pubSub1.registerNodeHandle(nh);
    pubSub1.registerPubSub();
    pubSub1.iniPub();

    ros::spin();
}

// 需要先启动 2B, 再启动 2A
// 因为2A中是一次性发送的msg，2B错过的话，就永远接收不到

// 当你一则消息都不想漏掉时让程序睡一会儿，等待节点连接起来再发布消息．
// 可以讲sleep时间加大，2A启动后，只要在这个时间内可以启动2B就没问题。