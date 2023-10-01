#pragma once
#include "robot_info/TwoStrVec.h"
#include "ros/publisher.h"
#include <ros/ros.h>
#include <string>
#include <vector>
using namespace std;

class RobotInfo {

public:
  const static std::string DEFAULT_NAMES[4];
  // ructor
  RobotInfo(ros::NodeHandle *node_handle, std::string *arrValue,
            const std::string *arrName = DEFAULT_NAMES);
  // can be moved into public?
  virtual void publish_data();

protected:
  ros::NodeHandle *nh; // field for ros node
  robot_info::TwoStrVec msg_info;
  ros::Publisher pub_info;
  // variable names for msg
  const std::string *names;
  std::string *values;

  void init_robot_info_msg() ;
  void init_robot_info_pub() ; 
};
