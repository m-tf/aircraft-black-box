#include "EventDetector.h"

#include <math.h>

// Creates the event detector with the aircraft's starting state
EventDetector::EventDetector(FlightState initialState)
{
    previousState = initialState;
    excessivePitchActive = false;
    previousAltitude = 0.0f;
    hasPreviousAltitude = false;
}

bool EventDetector::detectStateChange(FlightState currentState, FlightEvent& event)
{
    // Check if the aircraft has changed flight states
    if (previousState != currentState)
    {
        event.type = STATE_CHANGE;
        event.previousState = previousState;
        event.currentState = currentState;
        
        // Save the current state for the next check
        previousState = currentState;

        return true;
    }

    return false;

}

bool EventDetector::detectExcessivePitch(const SensorData& sensorData, FlightEvent& event)
{
    // Maximum safe pitch angle
    const float MAX_SAFE_PITCH = 20.0f;

    if (sensorData.pitch > MAX_SAFE_PITCH || sensorData.pitch < -MAX_SAFE_PITCH)
    {
        if (!excessivePitchActive)
        {
            // Set the detected event type
            event.type = EXCESSIVE_PITCH;
            event.sensorValue = sensorData.pitch;

            // Mark the excessive pitch condition as active
            excessivePitchActive = true;

            return true;
        }
        
    }

    else
    {
        // Check if the aircraft has recovered from excessive pitch
        if (excessivePitchActive)
        {
            event.type = PITCH_NORMAL;
            event.sensorValue = sensorData.pitch;

            // Pitch is safe again
            excessivePitchActive = false;

            return true;
        }
    }

    return false;
    
}

bool EventDetector::detectAltitudeFault(const SensorData& sensorData, FlightEvent& event)
{
    // Maximum allowed altitude change between sensor readings
    const float MAX_ALTITUDE_CHANGE = 200.0f;

    if (hasPreviousAltitude == false)
    {
        previousAltitude = sensorData.altitude;
        hasPreviousAltitude = true;

        return false;
    }

    float altitudeChange = std::abs(sensorData.altitude - previousAltitude);


    if (altitudeChange > MAX_ALTITUDE_CHANGE)
    {
        event.type = ALTITUDE_FAULT;
        event.sensorValue = sensorData.altitude;
        
        return true;
    }
    else
    {
        // Save the current altitude for the next sensor reading
        previousAltitude = sensorData.altitude;

        return false;
    }
    
}
