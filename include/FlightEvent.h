#ifndef FLIGHTEVENT_H
#define FLIGHTEVENT_H

#include "FlightData.h"

#include <string>

// Types of events that can be detected during a flight
enum EventType
{
    STATE_CHANGE,
    EXCESSIVE_PITCH,

    // Indicates the aircraft pitch has returned to a safe range
    PITCH_NORMAL,

    ALTITUDE_FAULT
};

// Converts an event type to a string
std::string eventTypeToString(EventType type);

// Contains the previous and current states of a flight event
struct FlightEvent
{
    EventType type;
    FlightState previousState;
    FlightState currentState;
    // Stores the sensor value that triggered the event
    float sensorValue;
};

#endif