/**
 * @file main.cpp
 * @author xm (xmain90@163.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>


#include "FaceDetector.h"
#include "DistanceCalculator.h"
#include "AlertSystem.h"

int main() 
{
    FaceDetector detector;
    DistanceCalculator calculator;
    const std::string modelConfig = "../models/deploy.prototxt";
    const std::string modelWeights = "../resources/res10_300x300_ssd_iter_140000_fp16.caffemodel";
    
    if (!detector.loadModel(modelConfig, modelWeights)) 
    {
        std::cerr << "Error loading model files!" << std::endl;
        return -1;
    }
    
    cv::VideoCapture cap(0); 
    if (!cap.isOpened()) 
    {
        std::cerr << "Error opening camera!" << std::endl;
        return -1;
    }
    
    printf("按 'c' 校准标准姿势，按 'q' 退出...\n");
    printf("Press 'c' to calibrate standard posture or press 'q' to exit...\n");
    bool isCalibrated = false;
    
    while (true) 
    {
        cv::Mat frame;

        // sleep for 3 second
        if(isCalibrated)
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }

        cap >> frame;
        if (frame.empty()) 
        {
            printf(
                "Error: Could not grab a frame from the camera. Exiting...\n"
            );
            break;
        }
        
        cv::Rect faceRect = detector.detectFace(frame);
        if (!faceRect.empty()) 
        {
            cv::rectangle(frame, faceRect, cv::Scalar(0, 255, 0), 2);
            float faceWidth = faceRect.width;
            
            int key = cv::waitKey(1);

            if (key == 'c') // 校准
            {
                calculator.calibrate(faceWidth);
                isCalibrated = true;
                printf("校准完成\n");
                printf("Calibration complete\n");
            } 
            else if (key == 'q') 
            {
                break;
            }
            
            if (isCalibrated && calculator.isTooClose(faceWidth)) 
            {
                
                AlertSystem::showAlert("距离过近！请调整坐姿！");
            }
        }
        
        cv::imshow("PostureGuard", frame);
    }
    
    cap.release();
    cv::destroyAllWindows();
    return 0;
}