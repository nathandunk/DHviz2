cmake_minimum_required(VERSION 3.12)

project(RobotSim VERSION 0.1 LANGUAGES C CXX)

include(FetchContent) 
FetchContent_Declare(mahi-robo GIT_REPOSITORY https://github.com/mahilab/mahi-robo.git) 
FetchContent_MakeAvailable(mahi-robo)

include_directories(src)

# set(dll_files
    # M.hpp
    # V.hpp
    # G.hpp
    # Params.hpp
    # Model.cpp
    # Model.hpp
    # DynamicModel.cpp)

add_library(dynamic_model SHARED src/M.hpp src/V.hpp src/G.hpp src/Params.hpp src/Model.hpp src/Model.cpp src/DynamicModel.cpp)
target_link_libraries(dynamic_model mahi::robo)

# add_executable(dynamic_model_exe src/M.hpp src/V.hpp src/G.hpp src/Params.hpp src/Model.hpp src/Model.cpp src/DynamicModelEXE.cpp)
# target_link_libraries(dynamic_model_exe mahi::robo)

# add_custom_command(TARGET robot_sim POST_BUILD 
            #    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            #    $<TARGET_FILE:robot_sim>              
            #    "${PROJECT_SOURCE_DIR}/../unity/RobotSim/Build/RobotSim_Data/Plugins/")