#pragma cling add_library_path("/Users/qliu/miniconda3/envs/a1/lib")
#pragma cling add_include_path("/Users/qliu/miniconda3/envs/a1/include")
#pragma cling load("opencv_core")
#pragma cling load("opencv_highgui")
#pragma cling load("opencv_imgcodecs")
#pragma cling load("opencv_imgproc")
#pragma cling load("opencv_calib3d")

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

// ===== Start of im::show()
// taken from https://github.com/jupyter-xeus/xeus-cling/issues/203
#include "xtl/xbase64.hpp"
#include "nlohmann/json.hpp"

namespace im
{
    struct matshow
    {
        matshow(const cv::Mat& m) : _mat(m) {}
        cv::Mat _mat;
    };;
    matshow show(const cv::Mat& m) { matshow r(m); return r; }

    nlohmann::json mime_bundle_repr(const matshow& m)
    {
        std::vector<uchar> buf;
        bool success =  cv::imencode(".png", m._mat, buf);
        if (success) {
            auto bundle = nlohmann::json::object();
            std::string buf_as_str(buf.begin(), buf.end());
            bundle["image/jpeg"] = xtl::base64encode(buf_as_str);
            return bundle;
        }
        else
            return {};
    }
}
// ===== End of im::show()

#include <iostream>
