#include <gtest/gtest.h>
#include "SignalGenerator.h"
#include "SignalProcessor.h"

TEST(SignalProcessorTest, ResampleSize)
{
    float frequency = 440.0f;
    float inputRate = 44100.0f;
    float outputRate = 22050.0f;
    float duration = 1.0f;

    std::vector<float> sineWave = SignalGenerator::generateSineWave(frequency, inputRate, duration);
    std::vector<float> resampledWave = SignalProcessor::resample(sineWave, inputRate, outputRate);

    EXPECT_EQ(resampledWave.size(), static_cast<size_t>(outputRate * duration));
}

TEST(SignalProcessorTest, LinearInterpolationSize)
{
    std::vector<float> input = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f};
    int newSize = 10;

    std::vector<float> interpolated = SignalProcessor::linearInterpolation(input, newSize);

    EXPECT_EQ(interpolated.size(), newSize);
}

TEST(SignalProcessorTest, LinearInterpolationValues)
{
    std::vector<float> input = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f};
    int newSize = 5;

    std::vector<float> interpolated = SignalProcessor::linearInterpolation(input, newSize);

    EXPECT_FLOAT_EQ(interpolated[0], 0.0f);
    EXPECT_FLOAT_EQ(interpolated[1], 1.0f);
    EXPECT_FLOAT_EQ(interpolated[2], 2.0f);
    EXPECT_FLOAT_EQ(interpolated[3], 3.0f);
    EXPECT_FLOAT_EQ(interpolated[4], 4.0f);
}