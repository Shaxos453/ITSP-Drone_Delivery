#!/bin/bash

source /opt/ros/melodic/setup.bash
source ~/catkin_ws/devel/setup.bash 

roslaunch rosbridge_server rosbridge_websocket.launch

