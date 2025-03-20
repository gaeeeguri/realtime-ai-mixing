#ifndef FILTER_PROCESSOR_H
#define FILTER_PROCESSOR_H

#include <vector>

class FilterProcessor
{
public:
    explicit FilterProcessor(const std::vector<float> &coefficients);
    std::vector<float> applyFilter(const std::vector<float> &input);

    static std::vector<float> applyIIRFilter(const std::vector<float> &input,
                                             const std::vector<float> &b,
                                             const std::vector<float> &a);

private:
    std::vector<float> coeffs;
    std::vector<float> buffer;
};

#endif // FILTER_PROCESSOR_H