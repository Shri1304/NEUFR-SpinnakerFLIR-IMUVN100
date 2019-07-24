cmake_minimum_required(VERSION 3.10)
project(vn_100_ws)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/imu_vn_100/include)
include_directories(src/imu_vn_100/include/imu_vn_100)
include_directories(src/imu_vn_100/vncpplib/include)

add_executable(vn_100_ws
        src/imu_vn_100/include/imu_vn_100/imu_vn_100.h
        src/imu_vn_100/src/imu_vn_100.cpp
        src/imu_vn_100/src/imu_vn_100_cont.cpp
        src/imu_vn_100/vncpplib/include/vectornav.h
        src/imu_vn_100/vncpplib/include/vn100.h
        src/imu_vn_100/vncpplib/include/vn200.h
        src/imu_vn_100/vncpplib/include/vn_common.h
        src/imu_vn_100/vncpplib/include/vn_errorCodes.h
        src/imu_vn_100/vncpplib/include/vn_kinematics.h
        src/imu_vn_100/vncpplib/include/vn_linearAlgebra.h
        src/imu_vn_100/vncpplib/include/vn_math.h
        src/imu_vn_100/vncpplib/include/vncp_services.h
        src/imu_vn_100/vncpplib/include/vndevice.h
        src/imu_vn_100/vncpplib/include/vnint.h
        src/imu_vn_100/vncpplib/src/arch/linux/vncp_services.c
        src/imu_vn_100/vncpplib/src/arch/win32/vncp_services.c
        src/imu_vn_100/vncpplib/src/vn100.c
        src/imu_vn_100/vncpplib/src/vn200.c
        src/imu_vn_100/vncpplib/src/vndevice.c)
