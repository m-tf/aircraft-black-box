#include "FlightSimulator.h"

void updateFlight(FlightData& aircraft, int time) {
    
    if (aircraft.flightState == PARKED)
    {
        if (time == 3)
        {
            aircraft.speed += 15.0f;
        }
        
    }
    else if (aircraft.flightState == TAXI)
    {
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
    }
    else if (aircraft.flightState == TAKEOFF)
    {
        aircraft.speed += 15.0f;
        aircraft.altitude += 100.0f;
        aircraft.pitch = 10.0f;
    }
    else if (aircraft.flightState == CLIMB)
    {
        aircraft.speed += 15.0f;
        aircraft.altitude += 100.0f;
        aircraft.pitch = 10.0f;
    }
    else if (aircraft.flightState == CRUISE)
    {
        aircraft.pitch = 0.0f;

        if (time > 20)
        {
            aircraft.altitude -= 100.0f;
            aircraft.pitch = -5.0f;
        }
    }
    else if (aircraft.flightState == DESCENT)
    {
        aircraft.altitude -= 100.0f;
        aircraft.pitch = -5.0f;
    }
    else if (aircraft.flightState == LANDING)
    {
        aircraft.pitch = 0.0f;

        if (aircraft.speed > 30.0f)
        {
            aircraft.speed -= 30.0f;
        }
        else {
            aircraft.speed = 0.0f;
        }
        
    }
}