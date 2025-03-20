#include "SignalProcessor.h"

std::vector<float> SignalProcessor::resample(const std::vector<float> &input, float inputRate, float outputRate)
{
    std::vector<float> output;
    float ratio = outputRate / inputRate;
    int newSize = static_cast<int>(input.size() * ratio);

    for (int i = 0; i < newSize; ++i)
    {
        float index = i / ratio;
        int low = static_cast<int>(index);
        int high = (low + 1 < input.size()) ? low + 1 : low;
        float fraction = index - low;

        output.push_back((1.0f - fraction) * input[low] + fraction * input[high]); // Linear interpolation
    }

    return output;
}

std::vector<float> SignalProcessor::linearInterpolation(const std::vector<float> &input, int newSize)
{
    std::vector<float> output;
    int oldSize = input.size();

    for (int i = 0; i < newSize; ++i)
    {
        float index = static_cast<float>(i) / (newSize - 1) * (oldSize - 1);
        int low = static_cast<int>(index);
        int high = (low + 1 < oldSize) ? low + 1 : low;
        float fraction = index - low;

        output.push_back((1.0f - fraction) * input[low] + fraction * input[high]); // Linear interpolation
    }

    return output;
}