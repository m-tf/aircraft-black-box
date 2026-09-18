#ifndef FLIGHTDATA_H
#define FLIGHTDATA_H

#include <string>

enum FlightState {
    PARKED,
    TAXI,
    TAKEOFF,
    CLIMB,
    CRUISE,
    DESCENT,
    LANDING
};

std::string flightStateToString(FlightState state);

struct FlightData
{
    float altitude;
    float speed;
    float pitch;
    float roll;
    FlightState flightState;
};

#endif
