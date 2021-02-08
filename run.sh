rm  -rf  build/*
rm  -rf  devel/*

catkin_make -j20

source devel/setup.bash

# roslaunch pub_sub_test pub_int8.launch
# roslaunch   read_param_test   read_param.launch
# roslaunch   read_param_test   read_param_from_yaml.launch
