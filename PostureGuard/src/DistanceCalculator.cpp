#include "DistanceCalculator.h"

void DistanceCalculator::calibrate(float referenceWidth) 
{
    referenceFaceWidth = referenceWidth;
}

bool DistanceCalculator::isTooClose(float currentWidth, float thresholdRatio) 
{
    if (referenceFaceWidth <= 0) return false; // 未校准
    return (currentWidth / referenceFaceWidth) > thresholdRatio;
}