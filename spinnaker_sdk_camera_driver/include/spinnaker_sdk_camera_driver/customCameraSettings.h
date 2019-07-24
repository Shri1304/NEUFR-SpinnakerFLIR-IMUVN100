//
// Created by auv on 7/23/19.
//

#ifndef SPINNAKER_SDK_CAMERA_DRIVER_CUSTOMCAMERASETTINGS_H
#define SPINNAKER_SDK_CAMERA_DRIVER_CUSTOMCAMERASETTINGS_H

#endif //SPINNAKER_SDK_CAMERA_DRIVER_CUSTOMCAMERASETTINGS_H


#include "Spinnaker.h"
#include "SpinGenApi/SpinnakerGenApi.h"
#include "capture.h"
#include <iostream>
#include <sstream>
#include <opencv-3.3.1-dev/opencv/cv.h>

#include "std_include.h"
#include "serialization.h"
#include "camera.h"

#include <boost/archive/binary_oarchive.hpp>
#include <boost/filesystem.hpp>
//ROS
#include "std_msgs/Float64.h"
#include "std_msgs/String.h"
//Dynamic reconfigure
#include <dynamic_reconfigure/server.h>
#include <spinnaker_sdk_camera_driver/spinnaker_camConfig.h>

#include "spinnaker_sdk_camera_driver/SpinnakerImageInfo.h"

#include <sstream>
#include <image_transport/image_transport.h>
#include <autoCameraSettings.h>
#include <customCameraSettings.h>

using namespace Spinnaker;
using namespace Spinnaker::GenApi;
using namespace Spinnaker::GenICam;
using namespace cv;
using namespace std;


namespace acquisition {

    class customCameraSettings {

        public:
        ~customCameraSettings();

        customCameraSettings(ros::NodeHandle node,ros::NodeHandle private_nh);

        void ConfigureCustomImageSettings(INodeMap & nodeMap)
    };
}