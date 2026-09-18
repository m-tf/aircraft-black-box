#include <iostream>

#include "FlightData.h"
#include "FlightSimulator.h"
#include "FlightComputer.h"
#include "DataLogger.h"
#include "Barometer.h"
#include "IMU.h"
#include "EventDetector.h"

int main() {
    FlightData aircraft;
    // Create the simulated barometer sensor
    Barometer barometer;
    // Create the simulated pitch sensor
    IMU imu;

    aircraft.altitude = 0.0f;
    aircraft.speed = 0.0f;
    aircraft.pitch = 0.0f;
    aircraft.roll = 0.0f;
    aircraft.flightState = PARKED;

    // Create the event detector
    EventDetector eventDetector(aircraft.flightState);


    // initialize datalog once
    initializeLog();

    for (int i = 1; i <= 40; i++)
    {
        updateFlight(aircraft, i);

        // Read the aircraft's altitude using the simulated barometer
        float measuredAltitude = barometer.readAltitude(aircraft.altitude);

        // Read the aircraft's pitch using the simulated IMU
        float measuredPitch = imu.readPitch(aircraft.pitch);

        // Update the flight state using the sensor measurement
        updateFlightState(aircraft, measuredAltitude, measuredPitch);

        // Print the changed flight state once state changes
        if (eventDetector.detectEvent(aircraft.flightState))
        {
            std::cout << "EVENT: Flight state changed to " << flightStateToString(aircraft.flightState) << std::endl;
        }
        

        // Log the aircraft data and sensor measurements
        logFlightData(aircraft, i, measuredAltitude, measuredPitch);
        
        std::cout << "Time: " << i << " sec" << std::endl;
        std::cout << "Altitude: " << aircraft.altitude << std::endl;
        std::cout << "Speed: " << aircraft.speed << std::endl;
        std::cout << "Pitch: " << aircraft.pitch << std::endl;
        std::cout << "State: " << flightStateToString(aircraft.flightState) << std::endl;
        std::cout << "Barometer: " << measuredAltitude << std::endl;
        std::cout << "IMU pitch: " << measuredPitch << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}