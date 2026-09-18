#include "FlightComputer.h"

void updateFlightState(FlightData& aircraft, float measuredAltitude, float measuredPitch) {

    // Treat small barometer readings as ground level to account for sensor error
    const float GROUND_ALTITUDE_THRESHOLD = 5.0f;
    // Altitude where the aircraft enters cruise
    const float CRUISE_ALTITUDE = 1000.0f;
    // Altitude the aircraft must fall below before leaving cruise
    const float CRUISE_EXIT_ALTITUDE = 990.0f;
    // Allows for small sensor errors when detecting cruise altitude
    const float CRUISE_ALTITUDE_TOLERANCE = 5.0f;
    // Ignores small IMY pitch changes caused by sensor noise
    const float PITCH_TOLERANCE = 1.0f;
 
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
    else if (measuredAltitude > 0 && measuredPitch < -PITCH_TOLERANCE)
    {
        aircraft.flightState = DESCENT;
    }
    else if (measuredAltitude > 0 && measuredAltitude < 300)
    {
        aircraft.flightState = TAKEOFF;
    }
    // keep the aircraft in cruise during small altitude fluctuations
    else if (aircraft.flightState == CRUISE &&
            measuredAltitude >= CRUISE_EXIT_ALTITUDE)
    {
        aircraft.flightState = CRUISE;
    }
    else if (measuredAltitude >= 300 &&
        measuredAltitude < CRUISE_ALTITUDE - CRUISE_ALTITUDE_TOLERANCE)
    {
        aircraft.flightState = CLIMB;
    }
    // Enter cruise when altitude is within the sensor tolerance
    else if (measuredAltitude >= CRUISE_ALTITUDE - CRUISE_ALTITUDE_TOLERANCE)
    {
        aircraft.flightState = CRUISE;
    }
}