#include <iostream>

#include "FlightData.h"
#include "FlightSimulator.h"
#include "FlightComputer.h"
#include "DataLogger.h"

int main() {
    FlightData aircraft;

    aircraft.altitude = 0.0f;
    aircraft.speed = 0.0f;
    aircraft.pitch = 0.0f;
    aircraft.roll = 0.0f;
    aircraft.flightState = "PARKED";

    // initialize datalog once
    initializeLog();

    for (int i = 1; i <= 20; i++)
    {
        updateFlight(aircraft, i);
        updateFlightState(aircraft);
        logFlightData(aircraft, i);
        std::cout << "Time: " << i << " sec" << std::endl;
        std::cout << "Altitude: " << aircraft.altitude << std::endl;
        std::cout << "Speed: " << aircraft.speed << std::endl;
        std::cout << "Pitch : " << aircraft.pitch << std::endl;
        std::cout << "State : " << aircraft.flightState << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}