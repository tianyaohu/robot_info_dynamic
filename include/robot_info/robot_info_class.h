#pragma once
#include "robot_info/TwoStrVec.h"
#include "ros/publisher.h"
#include <ros/ros.h>
#include <string>
#include <vector>
using namespace std;

class RobotInfo {

public:
  RobotInfo(){}; // default constructor
  // single vec param
  RobotInfo(ros::NodeHandle *node_handle, const std::vector<std::string> *vecValue);
  // two vec param
  RobotInfo(ros::NodeHandle *node_handle, const std::vector<std::string> *vecName,
            const vector<std::string> *vecValue);
  // can be moved into public?
  virtual void publish_data();

protected:
  ros::NodeHandle *nh; // field for ros node
  robot_info::TwoStrVec msg_info;
  ros::Publisher pub_info;

  void init_robot_info_msg(const std::vector<std::string> *names,
                           const std::vector<std::string> *values);
  void init_robot_info_pub(); // init method for starting service
};