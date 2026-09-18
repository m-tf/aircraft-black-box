#include "FlightEvent.h"

std::string eventTypeToString(EventType type)
{
    switch (type)
    {
        case STATE_CHANGE:
            return "STATE_CHANGE";

        case EXCESSIVE_PITCH:
            return "EXCESSIVE_PITCH";
        
        case PITCH_NORMAL:
            return "PITCH_NORMAL";

        case ALTITUDE_FAULT:
            return "ALTITUDE_FAULT";
            
        default:
                return "UNKNOWN";
    }
}