#ifndef FLIGHTDATA_H
#define FLIGHTDATA_H

#include <string>

struct FlightData
{
    float altitude;
    float speed;
    float pitch;
    float roll;
    std::string flightState;
};

#endif
