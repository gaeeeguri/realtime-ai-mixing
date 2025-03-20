#include "FilterProcessor.h"

FilterProcessor::FilterProcessor(const std::vector<float> &coefficients)
    : coeffs(coefficients), buffer(coefficients.size(), 0.0f) {}

std::vector<float> FilterProcessor::applyFilter(const std::vector<float> &input)
{
    std::vector<float> output(input.size(), 0.0f);
    int filterSize = coeffs.size();

    for (size_t i = 0; i < input.size(); ++i)
    {
        buffer.insert(buffer.begin(), input[i]); // 새로운 샘플 추가
        buffer.pop_back();                       // 오래된 샘플 제거

        float sum = 0.0f;
        for (int j = 0; j < filterSize; ++j)
        {
            sum += buffer[j] * coeffs[j];
        }
        output[i] = sum;
    }

    return output;
}

std::vector<float> FilterProcessor::applyIIRFilter(const std::vector<float> &input,
                                                   const std::vector<float> &b,
                                                   const std::vector<float> &a)
{
    std::vector<float> output(input.size(), 0.0f);
    int M = b.size(); // Feedforward 계수 개수
    int N = a.size(); // Feedback 계수 개수

    for (size_t n = 0; n < input.size(); ++n)
    {
        float sum = 0.0f;

        // Feedforward (FIR 부분)
        for (int k = 0; k < M; ++k)
        {
            if (n >= k)
            {
                sum += b[k] * input[n - k];
            }
        }

        // Feedback (IIR 부분)
        for (int k = 1; k < N; ++k)
        {
            if (n >= k)
            {
                sum -= a[k] * output[n - k];
            }
        }

        output[n] = sum;
    }

    return output;
}