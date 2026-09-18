#include <iostream>

#include "FlightData.h"
#include "FlightSimulator.h"
#include "FlightComputer.h"
#include "DataLogger.h"
#include "Barometer.h"
#include "IMU.h"
#include "EventDetector.h"
#include "FlightEvent.h"
#include "SensorData.h"


int main() {
    FlightData aircraft;
    // Create the simulated barometer sensor
    Barometer barometer;
    // Create the simulated pitch sensor
    IMU imu;
    // Stores measurements from the aircraft's sensors
    SensorData sensorData;

    aircraft.altitude = 0.0f;
    aircraft.speed = 0.0f;
    aircraft.pitch = 0.0f;
    aircraft.roll = 0.0f;
    aircraft.flightState = PARKED;

    // Create the event detector
    EventDetector eventDetector(aircraft.flightState);

    // Stores information about a detected flight event
    FlightEvent event;


    // initialize datalog once
    initializeLog();

    for (int i = 1; i <= 40; i++)
    {
        updateFlight(aircraft, i);

        // Read the aircraft's altitude using the simulated barometer
        if (i == 10)
        {
            // Simulate a faulty barometer reading
            sensorData.altitude = barometer.readFaultyAltitude(aircraft.altitude);
        }
        else
        {
            sensorData.altitude = barometer.readAltitude(aircraft.altitude);
        }

        // Read the aircraft's pitch using the simulated IMU
        sensorData.pitch = imu.readPitch(aircraft.pitch);

        // Check for an unrealistic change in altitude
        if (eventDetector.detectAltitudeFault(sensorData, event))
        {
            std::cout << "WARNING: Altitude sensor fault detected : "
                      << event.sensorValue
                      << " feet" << std::endl;
            
            logFlightEvent(event, i);
        }
        else
        {
            // Sensor data passed validation

            // Update the flight state using the sensor measurements
            updateFlightState(aircraft, sensorData);
        }
        

        // Check for excessive pitch fault
        if (eventDetector.detectExcessivePitch(sensorData, event))
        {
            if (event.type == EXCESSIVE_PITCH)
            {
            
                std::cout << "WARNING: Excessive pitch detected: " 
                        << event.sensorValue 
                        << " degrees" << std::endl;

            }
            else if (event.type == PITCH_NORMAL)
            {
                std::cout << "EVENT: Pitch returned to normal: "
                          << event.sensorValue
                          << " degrees" << std::endl;
            }
            
            logFlightEvent(event, i);
            
        }
        

        // Check for a change in the aircraft's flight state
        if (eventDetector.detectStateChange(aircraft.flightState, event))
        {
            std::cout << "EVENT: " 
                      << flightStateToString(event.previousState) 
                      << " -> " 
                      << flightStateToString(event.currentState) 
                      << std::endl;
            
            logFlightEvent(event, i);
        }
        

        // Log the aircraft data and sensor measurements
        logFlightData(aircraft, i, sensorData);
        
        std::cout << "Time: " << i << " sec" << std::endl;
        std::cout << "Altitude: " << aircraft.altitude << std::endl;
        std::cout << "Speed: " << aircraft.speed << std::endl;
        std::cout << "Pitch: " << aircraft.pitch << std::endl;
        std::cout << "State: " << flightStateToString(aircraft.flightState) << std::endl;
        std::cout << "Barometer: " << sensorData.altitude << std::endl;
        std::cout << "IMU pitch: " << sensorData.pitch << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}