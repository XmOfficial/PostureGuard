#include "FaceDetector.h"

FaceDetector::FaceDetector() 
{
    // 构造函数留空，模型通过loadModel加载
}

bool FaceDetector::loadModel(const std::string &config, const std::string &model) 
{
    net = cv::dnn::readNetFromCaffe(config, model);
    return !net.empty();
}

cv::Rect FaceDetector::detectFace(const cv::Mat &frame) 
{
    // 将输入图像转换为合适的格式
    cv::Mat blob = cv::dnn::blobFromImage(frame, 1.0, cv::Size(inputWidth, inputHeight), cv::Scalar(104, 177, 123));
    net.setInput(blob);
    cv::Mat detections = net.forward();
    
    cv::Rect maxRect;
    float maxConfidence = 0;
    
    // 遍历所有检测到的框
    for (int i = 0; i < detections.size[2]; ++i) 
    {
        // 使用 ptr 获取检测框的相关数据
        float confidence = detections.ptr<float>(0)[i * 7 + 2]; // 获取置信度
        if (confidence > confidenceThreshold && confidence > maxConfidence) 
        {
            int x1 = static_cast<int>(detections.ptr<float>(0)[i * 7 + 3] * frame.cols);  // 获取左上角x坐标
            int y1 = static_cast<int>(detections.ptr<float>(0)[i * 7 + 4] * frame.rows);  // 获取左上角y坐标
            int x2 = static_cast<int>(detections.ptr<float>(0)[i * 7 + 5] * frame.cols);  // 获取右下角x坐标
            int y2 = static_cast<int>(detections.ptr<float>(0)[i * 7 + 6] * frame.rows);  // 获取右下角y坐标
            maxRect = cv::Rect(x1, y1, x2 - x1, y2 - y1);  // 计算并存储最大置信度的矩形框
            maxConfidence = confidence;
        }
    }
    return maxRect;
}
