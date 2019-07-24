#include <spinnaker_sdk_camera_driver/autoCameraSettings.h>
#include <spinnaker_sdk_camera_driver/customCameraSettings.h>
#include "spinnaker_sdk_camera_driver/capture.h"

using namespace Spinnaker;
using namespace Spinnaker::GenApi;
using namespace Spinnaker::GenICam;
using namespace std;

int main(int argc, char** argv) {
    
    int result = 0;

    // Initializing the ros node
    ros::init(argc, argv, "acquisition_node");
    //spinners
    ros::AsyncSpinner spinner(0); // Use max cores possible for mt
    spinner.start();

    acquisition::Capture cobj;
    cobj.init_array();
    cobj.run();

    acquisition::autoCameraSettings obj;
    obj.ConfigureExposure();
    obj.ResetExposure();

    acquisition:: customCameraSettings obj1;
    obj1.ConfigureCustomImageSettings();

    return 0;
}
