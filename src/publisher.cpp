
#include <ros/ros.h>
#include <std_msgs/Int32.h> // Import all the necessary ROS libraries and import the Int32 message from the std_msgs package

int main(int argc, char** argv) {
        ros::init(argc, argv, "topic_publisher"); // Initiate a Node named 'topic_publisher'
        ros::NodeHandle nh;  //handler and are made with virtual function in class ros and who will make it will be responsible for handle the class 
        /* Create a Publisher object, that will // publish on the /counter topic messages // of type Int32
        ros::Rate loop_rate(2); // Set a publish rate of 2 Hz */
        ros::Publisher pub = nh.advertise<std_msgs::Int32>("counter", 1000);   //(<name of node>, 1000 = <queue size>)
        ros::Rate loop_rate(2);
        std_msgs::Int32 count; // Create a variable of type Int32 ,,,, we will take object from class Int32 named count and we will make 
        count.data = 0; // Initialize 'count' variable

    while (ros::ok()){  // Create a loop that will go until someone stops the program execution
        pub.publish(count); // Publish the message within the 'count' variable
        ROS_INFO("Publish message %d", count); 
        ros::spinOnce();
        loop_rate.sleep(); // Make sure the publish rate maintains at 2 Hz
        ++count.data; // Increment 'count' variable

    }   
    return 0;
    
}   

//cmake is edited