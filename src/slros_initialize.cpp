#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "l5";

// For Block l5/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_l5_std_msgs_Float64> Sub_l5_31;

// For Block l5/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_l5_std_msgs_Float64> Sub_l5_34;

// For Block l5/Subscribe3
SimulinkSubscriber<std_msgs::Float64, SL_Bus_l5_std_msgs_Float64> Sub_l5_54;

// For Block l5/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_l5_std_msgs_Float64> Pub_l5_18;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

