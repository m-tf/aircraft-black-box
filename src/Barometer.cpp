#include "Barometer.h"

// Returns the simulated altitude measurement
float Barometer::readAltitude(float actualAltitude)
{
    return actualAltitude + 2.0f;
}