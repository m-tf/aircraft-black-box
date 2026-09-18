#ifndef EVENTDETECTOR_H
#define EVENTDETECTOR_H

#include "FlightData.h"
#include "FlightEvent.h"

class EventDetector
{
private:
    FlightState previousState;

public:
    // Creates the event detector
    EventDetector(FlightState initialState);

    // Checks if the aircraft's flight state has changed
    bool detectEvent(FlightState currentState, FlightEvent& event);
};

#endif