#include "FlightSimulator.h"

void updateFlight(FlightData& aircraft, int time) {
    
    switch (aircraft.flightState)
    {
    case PARKED:
        if (time == 3)
        {
            aircraft.speed += 15.0f;
        }
        break;

    case TAXI:
        if (aircraft.speed < 45.0f)
        {
            aircraft.speed += 15.0f;
        }
        else
        {
            aircraft.speed += 15.0f;
            aircraft.altitude += 100.0f;
            aircraft.pitch = 10.0f;
        }
        break;

    case TAKEOFF:
        aircraft.speed += 15.0f;
        aircraft.altitude += 100.0f;
        aircraft.pitch = 10.0f;
        break;

    case CLIMB:
        aircraft.speed += 15.0f;
        aircraft.altitude += 100.0f;
        aircraft.pitch = 10.0f;
        break;
    
    case CRUISE:
        aircraft.pitch = 0.0f;

        if (time > 20)
        {
            aircraft.altitude -= 100.0f;
            aircraft.pitch = -5.0f;
        }
        break;
    
    case DESCENT:
        aircraft.altitude -= 100.0f;
        aircraft.pitch = -5.0f;
        break;
    
    case LANDING:
        aircraft.pitch = 0.0f;

        if (aircraft.speed > 30.0f)
        {
            aircraft.speed -= 30.0f;
        }
        else {
            aircraft.speed = 0.0f;
        }
        break;

    default:
        break;
    }
}