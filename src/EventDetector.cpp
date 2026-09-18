#include "EventDetector.h"

// Creates the event detector with the aircraft's starting state
EventDetector::EventDetector(FlightState initialState)
{
    previousState = initialState;
    excessivePitchActive = false;
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