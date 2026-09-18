#ifndef EVENTDETECTOR_H
#define EVENTDETECTOR_H

#include "FlightData.h"
#include "FlightEvent.h"
#include "SensorData.h"

class EventDetector
{
private:
    FlightState previousState;

public:
    // Creates the event detector
    EventDetector(FlightState initialState);

    // Checks if the aircraft's flight state has changed
    bool detectStateChange(FlightState currentState, FlightEvent& event);

    // Checks if the aircraft's pitch exceeds the safe limit
    bool detectExcessivePitch(const SensorData& sensorData, FlightEvent& event);
};

#endif