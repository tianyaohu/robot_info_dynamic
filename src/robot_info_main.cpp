#include "robot_info/robot_info_class.h" //header file required
#include <ros/ros.h>
#include <unistd.h>

// declear main function
int main(int argc, char **argv) {
  // start ros node with NODE_NAME (HAS TO MATCH LAUNCH FILE "name" field
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;
  vector<string> test({"test_description", "test_serial_number",
                       "test_ip_address", "test_firmware_version"});
  RobotInfo ri = RobotInfo(&nh, &test); // to init class pass address of ros node
  while(true){
    ri.publish_data();
    usleep(1000000);
  }
  ri.publish_data();
  ros::spin();                         // spin the ros node
}