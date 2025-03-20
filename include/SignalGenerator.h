#ifndef SIGNAL_GENERATOR_H
#define SIGNAL_GENERATOR_H

#include <vector>
#include <cmath>

class SignalGenerator
{
public:
    static std::vector<float> generateSineWave(float frequency, float sampleRate, float duration);
};

#endif // SIGNAL_GENERATOR_H