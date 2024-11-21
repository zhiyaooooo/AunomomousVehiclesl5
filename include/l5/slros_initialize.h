#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "l5_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block l5/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_l5_std_msgs_Float64> Sub_l5_31;

// For Block l5/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_l5_std_msgs_Float64> Sub_l5_34;

// For Block l5/Subscribe3
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_l5_std_msgs_Float64> Sub_l5_54;

// For Block l5/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_l5_std_msgs_Float64> Pub_l5_18;

void slros_node_init(int argc, char** argv);

#endif
