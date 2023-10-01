#include "robot_info/robot_info_class.h"
#include <ros/ros.h>
#include <vector>
// header file should already decleared all the messages required here.

const std::string RobotInfo::DEFAULT_NAMES[4] = {
    "robot_description", "serial_number", "ip_address", "firmware_version"};

// parameterized ructor
RobotInfo::RobotInfo(ros::NodeHandle *node_handle, std::string *arrValue,
                     const std::string *arrName)
    : nh(node_handle), values(arrValue), names(arrName) {

  //   while (!names->empty()) {
  //     ROS_INFO("Detected name: %s", names->c_str());
  //     names++;
  //   }

  // init info msg; start publisher
  init_robot_info_msg();
  init_robot_info_pub();
  // print to console
  ROS_INFO("RobotInfo Constructor finished");
}

// init info pub
void RobotInfo::init_robot_info_pub() {
  ROS_INFO("RobotInfo publisher created");
  pub_info = nh->advertise<robot_info::TwoStrVec>("robot_info", 1000);
}

// init info msg
void RobotInfo::init_robot_info_msg() {
  // assuming values are longer or
  while (!names->empty()) {
    // check if value is null, if so skip that variable
    if (!values->empty()) {
      msg_info.vec1.emplace_back(names->c_str());
      msg_info.vec2.emplace_back(values->c_str());
      ROS_INFO("info_msg_init field %s with %s.", names->c_str(),
               values->c_str());
    } else {
      ROS_INFO("info_msg_init Warning: %s field is empty, skipping this field.",
               names->c_str());
    }
    // increment counter
    names++;
    values++;
  }

  ROS_INFO("Information message finished initialization");
}

void RobotInfo::publish_data() {

  //   for (size_t i = 0; i < mesg.size(); i++) {
  //     std::cout << vec[i] << " ";
  //   }

  pub_info.publish(msg_info);
  ROS_INFO("Published Information message");
  ros::spinOnce();
}