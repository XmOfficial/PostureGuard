#pragma once

class DistanceCalculator 
{
public:
    void calibrate(float referenceWidth);
    bool isTooClose(float currentWidth, float thresholdRatio = 1.1);
    
private:
    float referenceFaceWidth = 0;
};