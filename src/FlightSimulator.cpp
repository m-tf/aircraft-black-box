#include "FlightSimulator.h"

void updateFlight(FlightData& aircraft, int time) {

    if (time >= 3 && aircraft.speed < 45.0f)
    {
        aircraft.speed += 15.0f;
    }
    else if (time >= 3 && aircraft.speed >= 45.0f)
    {
        if (aircraft.altitude < 1000.0f)
        {
        
        aircraft.speed += 15.0f;
        aircraft.altitude += 100.0f;
        aircraft.pitch = 10.0f;
        }
        else
        {
            aircraft.pitch = 0.0f;
            
        }
        
        
        
    }

}