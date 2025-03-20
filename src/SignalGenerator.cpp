#include "SignalGenerator.h"

std::vector<float> SignalGenerator::generateSineWave(float frequency, float sampleRate, float duration)
{
    std::vector<float> wave;
    int numSamples = static_cast<int>(sampleRate * duration);

    for (int i = 0; i < numSamples; ++i)
    {
        float t = static_cast<float>(i) / sampleRate;
        wave.push_back(std::sin(2.0f * M_PI * frequency * t));
    }

    return wave;
}