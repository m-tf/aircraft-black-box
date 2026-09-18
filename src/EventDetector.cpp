#include "EventDetector.h"

// Creates the event detector with the aircraft's starting state
EventDetector::EventDetector(FlightState initialState)
{
    previousState = initialState;
}

bool EventDetector::detectEvent(FlightState currentState, FlightEvent& event)
{
    // Check if the aircraft has changed flight states
    if (previousState != currentState)
    {
        event.previousState = previousState;
        event.currentState = currentState;
        
        // Save the current state for the next check
        previousState = currentState;

        return true;
    }

    return false;
    
}