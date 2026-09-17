#include "FlightComputer.h"

void updateFlightState(FlightData& aircraft) {
 
    if (aircraft.speed == 0)
    {
        aircraft.flightState = "PARKED";
    }
    else if (aircraft.speed > 0 && aircraft.altitude == 0)
    {
        aircraft.flightState = "TAXI";
    }
    else if (aircraft.altitude > 0 && aircraft.altitude < 300)
    {
        aircraft.flightState = "TAKEOFF";
    }
    else if (aircraft.altitude >= 300 && aircraft.altitude < 1000)
    {
        aircraft.flightState = "CLIMB";
    }
    else if (aircraft.altitude >= 1000)
    {
        aircraft.flightState = "CRUISE";
    }
    
    
    
    
}