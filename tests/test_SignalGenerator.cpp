#include <gtest/gtest.h>
#include "SignalGenerator.h"

TEST(SignalGeneratorTest, GenerateSineWaveSize)
{
    float frequency = 440.0f;
    float sampleRate = 44100.0f;
    float duration = 1.0f;

    std::vector<float> sineWave = SignalGenerator::generateSineWave(frequency, sampleRate, duration);

    // 샘플 개수가 정확한지 확인
    EXPECT_EQ(sineWave.size(), static_cast<size_t>(sampleRate * duration));
}

TEST(SignalGeneratorTest, GenerateSineWaveValueRange)
{
    float frequency = 440.0f;
    float sampleRate = 44100.0f;
    float duration = 1.0f;

    std::vector<float> sineWave = SignalGenerator::generateSineWave(frequency, sampleRate, duration);

    // 모든 값이 -1.0 ~ 1.0 사이인지 확인
    for (float sample : sineWave)
    {
        EXPECT_GE(sample, -1.0f);
        EXPECT_LE(sample, 1.0f);
    }
}

TEST(SignalGeneratorTest, GenerateSquareWaveSize)
{
    float frequency = 440.0f;
    float sampleRate = 44100.0f;
    float duration = 1.0f;

    std::vector<float> squareWave = SignalGenerator::generateSquareWave(frequency, sampleRate, duration);

    EXPECT_EQ(squareWave.size(), static_cast<size_t>(sampleRate * duration));
}

TEST(SignalGeneratorTest, GenerateSquareWaveValues)
{
    float frequency = 440.0f;
    float sampleRate = 44100.0f;
    float duration = 1.0f;

    std::vector<float> squareWave = SignalGenerator::generateSquareWave(frequency, sampleRate, duration);

    for (float sample : squareWave)
    {
        EXPECT_TRUE(sample == 1.0f || sample == -1.0f);
    }
}

TEST(SignalGeneratorTest, GenerateTriangleWaveSize)
{
    float frequency = 440.0f;
    float sampleRate = 44100.0f;
    float duration = 1.0f;

    std::vector<float> triangleWave = SignalGenerator::generateTriangleWave(frequency, sampleRate, duration);

    EXPECT_EQ(triangleWave.size(), static_cast<size_t>(sampleRate * duration));
}

TEST(SignalGeneratorTest, GenerateTriangleWaveValueRange)
{
    float frequency = 440.0f;
    float sampleRate = 44100.0f;
    float duration = 1.0f;

    std::vector<float> triangleWave = SignalGenerator::generateTriangleWave(frequency, sampleRate, duration);

    for (float sample : triangleWave)
    {
        EXPECT_GE(sample, -1.0f);
        EXPECT_LE(sample, 1.0f);
    }
}

TEST(SignalGeneratorTest, GenerateWhiteNoiseSize)
{
    float sampleRate = 44100.0f;
    float duration = 1.0f;

    std::vector<float> whiteNoise = SignalGenerator::generateWhiteNoise(sampleRate, duration);

    EXPECT_EQ(whiteNoise.size(), static_cast<size_t>(sampleRate * duration));
}

TEST(SignalGeneratorTest, GenerateWhiteNoiseValueRange)
{
    float sampleRate = 44100.0f;
    float duration = 1.0f;

    std::vector<float> whiteNoise = SignalGenerator::generateWhiteNoise(sampleRate, duration);

    for (float sample : whiteNoise)
    {
        EXPECT_GE(sample, -1.0f);
        EXPECT_LE(sample, 1.0f);
    }
}