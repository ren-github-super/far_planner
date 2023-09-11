#ifndef GOALPOINT_RVIZ_PLUGIN_WAYPOINT_TOOL_H
#define GOALPOINT_RVIZ_PLUGIN_WAYPOINT_TOOL_H

#include <sstream>
#include <ros/ros.h>
#include <QObject>

#include <sensor_msgs/Joy.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PointStamped.h>

#include "rviz/display_context.h"
#include "rviz/properties/string_property.h"
#include "rviz/default_plugin/tools/pose_tool.h"
// #include "rviz/default_plugin/tools/goal_tool.h" //完全是基于Poseool的类构造函数来实现的
namespace rviz
{
class StringProperty;

class GoalPointTool : public PoseTool //GoalPointTool公有继承PoseTool
{
  Q_OBJECT  //后边需要用到的qt的信号，都是QObject的子类，所以需要声明Q_OBJECT宏
public:
  GoalPointTool();
  virtual ~GoalPointTool()
  {
  }
  virtual void onInitialize();

protected:
  virtual void odomHandler(const nav_msgs::Odometry::ConstPtr& odom);
  virtual void onPoseSet(double x, double y, double theta);

private Q_SLOTS:  //私人槽
  void updateTopic();

private:
  float vehicle_z;

  ros::NodeHandle nh_;
  ros::Subscriber sub_;
  ros::Publisher pub_;
  ros::Publisher pub_joy_;

  StringProperty* topic_property_;
};
}

#endif  // GOALPOINT_RVIZ_PLUGIN_WAYPOINT_TOOL_H
