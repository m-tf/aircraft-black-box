#include "IMU.h"

IMU::IMU()
{
    // Generate a random seed
    std::random_device rd;

    // Create the random number generator
    generator = std::mt19937(rd());
}

// Returns the simulation aircraft pitch
float IMU::readPitch(float actualPitch)
{
    // Set the range for simulated IMU pitch noise
    std::uniform_real_distribution<float> noise(-0.5f, 0.5f);

    float pitchNoise = noise(generator);


    return actualPitch + pitchNoise;
}
