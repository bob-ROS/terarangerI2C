#include <ros/ros.h>
#include "std_msgs"
#include "std_msgs/Range"

#define address 0x31
#define frequency 400
#define true 1
#define false 0

void mySigintHandler(int sig){
	// Do some custom action
	// Shutdown
	ros::shutdown();
}

int main(int argc, char **argv){

	ros::init(argc, argv, "Rangefinder");
	ros::NodeHandle n;

	std_msgs::Range my_sensor;
	while (ros::ok()){
	my_sensor.radiation_type = 1;
	my_sensor.field_of_view = 0.034906585;
	my_sensor.min_range = 0.5;
	my_sensor.max_range = 60;
	my_sensor.range |= 0x63;
	// *(outbuffer - 1) |= 0x80;
	ROS_INFO("Fistance: %f", my_sensor.range);

	}
}
