#include <ros/ros.h>
#include <mavros_msgs/WaypointSetCurrent.h>
#include <std_msgs/Bool>

void getStatus(std_msgs::Bool delry)

mavros_msgs::WaypointSetCurrent setCurrent;

bool delivered;

int main(int argc, char** argv){

    ros::init(argc, argv, "deploy_UAV0");
    ros::NodeHandle n;

    ros::Subscriber del = nh.subscribe <std_msgs::Bool>
        ("delivered0", 100, getStatus);
    ros::ServiceClient droneReturn = c.serviceClient<mavros_msgs::WaypointSetCurrent>
        ("/uav0/mavros/mission/set_current");

    while(ros::ok()){
        if(!delivered){
            if(droneReturn.call(setCurrent)){
                if(setCurrent.response.success){
                    ROS_INFO("DRONE RETURN INITIATED");
                }
                else{
                    ROS_INFO("FAILED TO SET CURRENT WAYPOINT");
                }
            }
            else{
                ROS_INFO("FAILED TO CALLED SET CURRENT SERVICE");
            }
        }
    }
}


void getStatus(std_msgs::Bool delry)
{
    status = delry.data;
    if(status)
        setCurrent.request.wp_seq = 5;
        delivered = true;
}