#ifndef BAROMETER_H
#define BAROMETER_H
#include <random>

// Simulates a barometer sensor used to measure aircraft altitude
class Barometer
{
private:
    std::mt19937 generator;
public:
    // Creates the barometer and initializes its random number generator
    Barometer();

    // Returns the measured altitude based on the aircraft's actual altitude
    float readAltitude(float actualAltitude);

    // Returns an intentionally faulty altitude measurement for testing
    float readFaultyAltitude(float actualAltitude);
};

#endif