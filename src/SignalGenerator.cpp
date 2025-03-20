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

std::vector<float> SignalGenerator::generateSquareWave(float frequency, float sampleRate, float duration)
{
    std::vector<float> wave;
    int numSamples = static_cast<int>(sampleRate * duration);
    float period = 1.0f / frequency;

    for (int i = 0; i < numSamples; ++i)
    {
        float t = static_cast<float>(i) / sampleRate;
        float cyclePosition = std::fmod(t, period) / period;

        if (cyclePosition < 0.5f)
        {
            wave.push_back(1.0f);
        }
        else
        {
            wave.push_back(-1.0f);
        }
    }

    return wave;
}

std::vector<float> SignalGenerator::generateTriangleWave(float frequency, float sampleRate, float duration)
{
    std::vector<float> wave;
    int numSamples = static_cast<int>(sampleRate * duration);
    float period = 1.0f / frequency;

    for (int i = 0; i < numSamples; ++i)
    {
        float t = static_cast<float>(i) / sampleRate;
        float cyclePosition = std::fmod(t, period) / period;

        float value = 4.0f * cyclePosition - 1.0f;
        if (cyclePosition > 0.5f)
        {
            value = 3.0f - 4.0f * cyclePosition;
        }

        wave.push_back(value);
    }

    return wave;
}

std::vector<float> SignalGenerator::generateWhiteNoise(float sampleRate, float duration)
{
    std::vector<float> wave;
    int numSamples = static_cast<int>(sampleRate * duration);

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

    for (int i = 0; i < numSamples; ++i)
    {
        wave.push_back(distribution(generator));
    }

    return wave;
}