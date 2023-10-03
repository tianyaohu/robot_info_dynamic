#include "robot_info/agv_robot_info_class.h"
#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle, std::string *arrValue,
                           const std::string *arrName)
    : RobotInfo(node_handle, arrValue, arrName) {}

void AGVRobotInfo::init_max_payload(std::string *max_load) {
  if (!max_load->empty()) {
    msg_info.vec1.emplace_back("maximum_payload");
    msg_info.vec2.emplace_back(max_load->c_str());
    max_load++; // change pointer to empty;
  }
}

void AGVRobotInfo::publish_data() {
  pub_info.publish(msg_info);
  ros::spinOnce();
  ROS_INFO("AGV infor node Published Information message");
}
