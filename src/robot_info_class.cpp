#include "robot_info/robot_info_class.h"
#include <ros/ros.h>
// header file should already decleared all the messages required here.

RobotInfo::RobotInfo(ros::NodeHandle *node_handle, std::vector<std::string> *vecValue) {
  // init ros node
  nh = node_handle;
  // default value names
  std::vector<std::string> vecName(
      {"robot_description", "serial_number", "ip_address", "firmware_version"});

  ROS_INFO("RobotInfo initialized with default fields");
  // init info msg
  init_robot_info_msg(&vecName, vecValue);
  init_robot_info_pub(); // starting publisher
}

// parameterized constructor
RobotInfo::RobotInfo(ros::NodeHandle *node_handle, std::vector<std::string> *vecName,
                     std::vector<std::string> *vecValue)
    : RobotInfo::RobotInfo(node_handle, vecValue) {
  init_robot_info_msg(vecName, vecValue);
}

// init info pub
void RobotInfo::init_robot_info_pub() {
  pub_info = nh->advertise<robot_info::TwoStrVec>("robot_info", 1000);
  ROS_INFO("RobotInfo publisher created");
}

// init info msg
void RobotInfo::init_robot_info_msg(std::vector<std::string> *names,
                                    std::vector<std::string> *values) {
  msg_info.vec1 = *names;
  msg_info.vec2 = *values;
  ROS_INFO("Information message initialized");
}

void RobotInfo::publish_data() {
  pub_info.publish(msg_info);
  ROS_INFO("Published Information message");
  ros::spinOnce();
}