#ifndef EVENTDETECTOR_H
#define EVENTDETECTOR_H

#include "FlightData.h"
#include "FlightEvent.h"
#include "SensorData.h"

class EventDetector
{
private:
    FlightState previousState;
    
    // Tracks whether an excessive pitch condition is currently active
    bool excessivePitchActive;

    // Stores the previous altitude measurement
    float previousAltitude;

    // Tracks whether an altitude measurement has already been stored
    bool hasPreviousAltitude;

    // Tracks whether the previous altitude reading was rejected
    bool altitudeFaultActive;

public:
    // Creates the event detector
    EventDetector(FlightState initialState);

    // Checks if the aircraft's flight state has changed
    bool detectStateChange(FlightState currentState, FlightEvent& event);

    // Checks if the aircraft's pitch exceeds the safe limit
    bool detectExcessivePitch(const SensorData& sensorData, FlightEvent& event);

    // Checks for an unrealistic change in altitude
    bool detectAltitudeFault(const SensorData& sensorData, FlightEvent& event);
};

#endif