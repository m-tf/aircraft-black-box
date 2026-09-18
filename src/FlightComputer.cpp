#include "FlightComputer.h"

void updateFlightState(FlightData& aircraft, float measuredAltitude) {

    // Treat small barometer readings as ground level to account for sensor error
    const float GROUND_ALTITUDE_THRESHOLD = 5.0f;
 
    if (aircraft.speed == 0)
    {
        aircraft.flightState = PARKED;
    }
    else if (measuredAltitude <= GROUND_ALTITUDE_THRESHOLD && aircraft.speed > 0 &&
            (aircraft.flightState == DESCENT || aircraft.flightState == LANDING))
    {
        aircraft.flightState = LANDING;
    }
    
    else if (aircraft.speed > 0 && 
            measuredAltitude <= GROUND_ALTITUDE_THRESHOLD)
    {
        aircraft.flightState = TAXI;
    }
    else if (measuredAltitude > 0 && aircraft.pitch < 0)
    {
        aircraft.flightState = DESCENT;
    }
    else if (measuredAltitude > 0 && measuredAltitude < 300)
    {
        aircraft.flightState = TAKEOFF;
    }
    else if (measuredAltitude >= 300 && measuredAltitude < 1000)
    {
        aircraft.flightState = CLIMB;
    }
    else if (measuredAltitude >= 1000)
    {
        aircraft.flightState = CRUISE;
    }
}