#include "FlightData.h"

std::string flightStateToString(FlightState state)
{
    switch (state)
    {
        case PARKED:
            return "PARKED";
        case TAXI:
            return "TAXI";
        case TAKEOFF:
            return "TAKEOFF";
        case CLIMB:
            return "CLIMB";
        case CRUISE:
            return "CRUISE";
        case DESCENT:
            return "DESCENT";
        case LANDING:
            return "LANDING";
        default:
            return "UNKNOWN";
    }
}