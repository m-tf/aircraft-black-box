#include "Barometer.h"

Barometer::Barometer()
{
    // Generate a random seed
    std::random_device rd;

    // Create the random number generator
    generator = std::mt19937(rd());
}

// Returns the simulated altitude measurement
float Barometer::readAltitude(float actualAltitude)
{
    // Set the range for simulated barometer noise
    std::uniform_real_distribution<float> noise(-2.0f, 2.0f);

    float sensorNoise = noise(generator);

    return actualAltitude + sensorNoise;
}

float Barometer::readFaultyAltitude(float actualAltitude)
{
    // Simulate a barometer reading 100 feet above the actual altitude
    return actualAltitude + 1000.0f;
}