
#include "spinnaker_sdk_camera_driver/customCameraSettings.h"


void acquisition::customCameraSettings:: ConfigureCustomImageSettings(INodeMap & nodeMap)
{
    int result = 0;
    cout << endl << endl << "*** CONFIGURING CUSTOM IMAGE SETTINGS ***" << endl << endl;
    try
    {
        //
        // Apply mono 8 pixel format
        //
        // *** NOTES ***
        // Enumeration nodes are slightly more complicated to set than other
        // nodes. This is because setting an enumeration node requires working
        // with two nodes instead of the usual one.
        //
        // As such, there are a number of steps to setting an enumeration node:
        // retrieve the enumeration node from the nodemap, retrieve the desired
        // entry node from the enumeration node, retrieve the integer value from
        // the entry node, and set the new value of the enumeration node with
        // the integer value from the entry node.
        //
        // Retrieve the enumeration node from the nodemap
        CEnumerationPtr ptrPixelFormat = nodeMap.GetNode("PixelFormat");
        if (IsAvailable(ptrPixelFormat) && IsWritable(ptrPixelFormat))
        {
            // Retrieve the desired entry node from the enumeration node
            CEnumEntryPtr ptrPixelFormatMono8 = ptrPixelFormat->GetEntryByName("Mono8");
            if (IsAvailable(ptrPixelFormatMono8) && IsReadable(ptrPixelFormatMono8))
            {
                // Retrieve the integer value from the entry node
                int64_t pixelFormatMono8 = ptrPixelFormatMono8->GetValue();
                // Set integer as new value for enumeration node
                ptrPixelFormat->SetIntValue(pixelFormatMono8);
                cout << "Pixel format set to " << ptrPixelFormat->GetCurrentEntry()->GetSymbolic() << "..." << endl;
            }
            else
            {
                cout << "Pixel format mono 8 not available..." << endl;
            }
        }
        else
        {
            cout << "Pixel format not available..." << endl;
        }
        //
        // Apply minimum to offset X
        //
        // *** NOTES ***
        // Numeric nodes have both a minimum and maximum. A minimum is retrieved
        // with the method GetMin(). Sometimes it can be important to check
        // minimums to ensure that your desired value is within range.
        //
        CIntegerPtr ptrOffsetX = nodeMap.GetNode("OffsetX");
        if (IsAvailable(ptrOffsetX) && IsWritable(ptrOffsetX))
        {
            ptrOffsetX->SetValue(ptrOffsetX->GetMin());
            cout << "Offset X set to " << ptrOffsetX->GetMin() << "..." << endl;
        }
        else
        {
            cout << "Offset X not available..." << endl;
        }
        //
        // Apply minimum to offset Y
        //
        // *** NOTES ***
        // It is often desirable to check the increment as well. The increment
        // is a number of which a desired value must be a multiple of. Certain
        // nodes, such as those corresponding to offsets X and Y, have an
        // increment of 1, which basically means that any value within range
        // is appropriate. The increment is retrieved with the method GetInc().
        //
        CIntegerPtr ptrOffsetY = nodeMap.GetNode("OffsetY");
        if (IsAvailable(ptrOffsetY) && IsWritable(ptrOffsetY))
        {
            ptrOffsetY->SetValue(ptrOffsetY->GetMin());
            cout << "Offset Y set to " << ptrOffsetY->GetValue() << "..." << endl;
        }
        else
        {
            cout << "Offset Y not available..." << endl;
        }
        //
        // Set maximum width
        //
        // *** NOTES ***
        // Other nodes, such as those corresponding to image width and height,
        // might have an increment other than 1. In these cases, it can be
        // important to check that the desired value is a multiple of the
        // increment. However, as these values are being set to the maximum,
        // there is no reason to check against the increment.
        //
        CIntegerPtr ptrWidth = nodeMap.GetNode("Width");
        if (IsAvailable(ptrWidth) && IsWritable(ptrWidth))
        {
            int64_t widthToSet = ptrWidth->GetMax();
            ptrWidth->SetValue(widthToSet);
            cout << "Width set to " << ptrWidth->GetValue() << "..." << endl;
        }
        else
        {
            cout << "Width not available..." << endl;
        }
        //
        // Set maximum height
        //
        // *** NOTES ***
        // A maximum is retrieved with the method GetMax(). A node's minimum and
        // maximum should always be a multiple of its increment.
        //
        CIntegerPtr ptrHeight = nodeMap.GetNode("Height");
        if (IsAvailable(ptrHeight) && IsWritable(ptrHeight))
        {
            int64_t heightToSet = ptrHeight->GetMax();
            ptrHeight->SetValue(heightToSet);
            cout << "Height set to " << ptrHeight->GetValue() << "..." << endl << endl;
        }
        else
        {
            cout << "Height not available..." << endl << endl;
        }
    }
    catch (Spinnaker::Exception &e)
    {
        cout << "Error: " << e.what() << endl;
        result = -1;
    }
    return result;
}