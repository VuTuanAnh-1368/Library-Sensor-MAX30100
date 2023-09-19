#ifndef MAX30100_SPO2CALCULATOR_H
#define MAX30100_SPO2CALCULATOR_H

#include <stdint.h>
#define CALCULATE_EVERY_N_BEATS         3

class SpO2Calculator {
public:
    SpO2Calculator();

    void update(float irACValue, float redACValue, bool beatDetected);
    void reset();
    uint8_t getSpO2();

private:
    static const uint8_t spO2LUT[43];

    float irACValueSqSum;
    float redACValueSqSum;
    uint8_t beatsDetectedNum;
    uint32_t samplesRecorded;
    uint8_t spO2;
};

#endif
