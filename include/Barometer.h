#ifndef BAROMETER_H
#define BAROMETER_H

// Simulates a barometer sensor used to measure aircraft altitude
class Barometer
{
public:
    // Returns the measured altitude based on the aircraft's actual altitude
    float readAltitude(float actualAltitude);
};

#endif