#include <iostream>

#include "FlightData.h"
#include "FlightSimulator.h"
#include "FlightComputer.h"
#include "DataLogger.h"
#include "Barometer.h"

int main() {
    FlightData aircraft;
    //create the simulated barometer sensor
    Barometer barometer;

    aircraft.altitude = 0.0f;
    aircraft.speed = 0.0f;
    aircraft.pitch = 0.0f;
    aircraft.roll = 0.0f;
    aircraft.flightState = PARKED;

    // initialize datalog once
    initializeLog();

    for (int i = 1; i <= 40; i++)
    {
        updateFlight(aircraft, i);

        // Read the aircraft's altitude using the simulated barometer
        float measuredAltitude = barometer.readAltitude(aircraft.altitude);

        // Update the flight state using the sensor measurement
        updateFlightState(aircraft, measuredAltitude);
        logFlightData(aircraft, i);
        
        std::cout << "Time: " << i << " sec" << std::endl;
        std::cout << "Altitude: " << aircraft.altitude << std::endl;
        std::cout << "Speed: " << aircraft.speed << std::endl;
        std::cout << "Pitch: " << aircraft.pitch << std::endl;
        std::cout << "State: " << flightStateToString(aircraft.flightState) << std::endl;
        std::cout << "Barometer: " << measuredAltitude << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}