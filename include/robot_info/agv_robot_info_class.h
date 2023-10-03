#pragma once
#include "robot_info/robot_info_class.h"
#include "ros/node_handle.h"
#include <ros/ros.h>
#include <string>
#include <vector>
using namespace std;

class AGVRobotInfo : private RobotInfo {
public:
  AGVRobotInfo(ros::NodeHandle *node_handle, std::string *arrValue,
               const std::string *arrName = DEFAULT_NAMES);
  void publish_data() override;

  void init_max_payload(std::string *max_load);

private:
  std::string *maximum_payload;
};