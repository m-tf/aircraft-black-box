#ifndef IMU_H
#define IMU_H

#include <random>

class IMU
{
private:
    std::mt19937 generator;
    
public:
    // Creates the IMU and initializes its random number generator
    IMU();
    // Returns measured pitch based on the aircraft's actual pitch
    float readPitch(float actualPitch);
};

#endif