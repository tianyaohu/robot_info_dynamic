#include "robot_info/agv_robot_info_class.h" //header file required
#include <ros/ros.h>

// declear main function
int main(int argc, char **argv) {
  // start ros node with NODE_NAME (HAS TO MATCH LAUNCH FILE "name" field
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;
  string test[4] = {"Mir100", "56 7A359", "169.254.5.180",
                    "3.5.8"};
  AGVRobotInfo ri =
      AGVRobotInfo(&nh, test); // to init class pass address of ros node
  // init payload
  std::string payload = "100 kg";
  ri.init_max_payload(&payload);
  while (nh.ok()) {
    ri.publish_data();
    usleep(1000000);
  }
  ri.publish_data();
  ros::spin(); // spin the ros node
}