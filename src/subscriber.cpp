#include <ros/ros.h>
#include <std_msgs/Int32.h>
// Define a function called 'callback' that receives a parameter named 'msg'
void counterCallback(const std_msgs::Int32::ConstPtr& msg)
{
ROS_INFO("%d", msg->data); // Print the value 'data' inside the 'msg' parameter
}
int main(int argc, char **argv) {
ros::init(argc, argv, "topic_subscriber"); // Initiate a Node called 'topic_subscriber'
ros::NodeHandle nh;
/* Create a Subscriber object that will listen to the /counter topic and will
call the 'callback' function each time it reads something from the topic */
ros::Subscriber sub = nh.subscribe("counter", 1000, counterCallback);
ros::spin(); // Create a loop that will keep the program in execution
return 0;
}


  //cmake is edited 
