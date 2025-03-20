#ifndef SIGNAL_GENERATOR_H
#define SIGNAL_GENERATOR_H

#include <vector>
#include <cmath>
#include <random>

class SignalGenerator
{
public:
    static std::vector<float> generateSineWave(float frequency, float sampleRate, float duration);
    static std::vector<float> generateSquareWave(float frequency, float sampleRate, float duration);
    static std::vector<float> generateTriangleWave(float frequency, float sampleRate, float duration);
    static std::vector<float> generateWhiteNoise(float sampleRate, float duration);
};

#endif // SIGNAL_GENERATOR_H