#ifndef SIGNAL_PROCESSOR_H
#define SIGNAL_PROCESSOR_H

#include <vector>

class SignalProcessor
{
public:
    static std::vector<float> resample(const std::vector<float> &input, float inputRate, float outputRate);
    static std::vector<float> linearInterpolation(const std::vector<float> &input, int newSize);
};

#endif // SIGNAL_PROCESSOR_H