#include <opencv2/opencv.hpp>

class FaceDetector 
{
public:
    FaceDetector();
    cv::Rect detectFace(const cv::Mat &frame);
    bool loadModel(const std::string &config, const std::string &model);
    
private:
    cv::dnn::Net net;
    const int inputWidth = 300;
    const int inputHeight = 300;
    const float confidenceThreshold = 0.7;
};