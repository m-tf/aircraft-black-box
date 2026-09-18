#include "FlightEvent.h"

std::string eventTypeToString(EventType type)
{
    switch (type)
    {
        case STATE_CHANGE:
            return "STATE_CHANGE";

        case EXCESSIVE_PITCH:
            return "EXCESSIVE_PITCH";
            
        default:
                return "UNKNOWN";
    }
}