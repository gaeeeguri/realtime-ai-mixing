#include <gtest/gtest.h>
#include "SignalGenerator.h"
#include "FilterProcessor.h"

TEST(FilterProcessorTest, ApplyIIRFilterSize)
{
    float frequency = 440.0f;
    float sampleRate = 44100.0f;
    float duration = 1.0f;

    std::vector<float> sineWave = SignalGenerator::generateSineWave(frequency, sampleRate, duration);

    std::vector<float> b = {0.2929f, 0.5858f, 0.2929f};
    std::vector<float> a = {1.0000f, -0.0000f, 0.1716f};

    std::vector<float> filteredSignal = FilterProcessor::applyIIRFilter(sineWave, b, a);

    EXPECT_EQ(filteredSignal.size(), sineWave.size());
}

TEST(FilterProcessorTest, IIRFilterStability)
{
    std::vector<float> impulse = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    std::vector<float> b = {0.5f, 0.5f};
    std::vector<float> a = {1.0f, -0.5f};

    std::vector<float> output = FilterProcessor::applyIIRFilter(impulse, b, a);

    EXPECT_NEAR(output[0], 0.5f, 0.01f);
    EXPECT_NEAR(output[1], 0.75f, 0.01f);
    EXPECT_NEAR(output[2], 0.625f, 0.01f);
}