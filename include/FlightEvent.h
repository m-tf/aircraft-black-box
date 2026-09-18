#ifndef FLIGHTEVENT_H
#define FLIGHTEVENT_H

#include "FlightData.h"


// Contains the  previous and current states of a flight event
struct FlightEvent
{
    FlightState previousState;
    FlightState currentState;
};

#endif