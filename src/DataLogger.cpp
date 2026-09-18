#include "DataLogger.h"

#include <fstream>
#include <string>


int currentFlight = 0;

void initializeLog() {

    // Log flight data
    std::ifstream flightReadFile("flight_log.csv");

    if (!flightReadFile.is_open())
    {
        // no previous log
        currentFlight = 1;
        std::ofstream loadFile("flight_log.csv");
        //Create the CSV header
        loadFile << "flight,time,actual_altitude,measured_altitude,speed,actual_pitch,measured_pitch,roll,state" << std::endl;
    }
    else {
        // previous log exists
        // read and figure out last flight number
        std::string line;

        // read one line here to skip the header
        std::getline(flightReadFile, line);

        int lastFlight = 0;

        while (std::getline(flightReadFile, line))
        {
            std::size_t firstComma = line.find(',');               // find first comma
            std::string flightNumber = line.substr(0, firstComma); // gets "1" (hopefully)
            lastFlight = std::stoi(flightNumber);              // converts "1" -> 1
        }
        currentFlight = lastFlight + 1;
    }

    // Log event data
    std::ifstream eventReadFile("event_log.csv");

    if (!eventReadFile.is_open())
    {
        // No previous log
        std::ofstream eventFile("event_log.csv");

        // Create the CSV header
        eventFile << "flight,time,event_type,previous_state,current_state,sensor_value" << std::endl;
    }

    
    
    
}

void logFlightData(const FlightData& aircraft, int time, const SensorData& sensorData) {

    std::ofstream loadFile("flight_log.csv", std::ios::app);

    loadFile << currentFlight << ","
             << time << ","
             << aircraft.altitude << ","
             << sensorData.altitude << ","
             << aircraft.speed << ","
             << aircraft.pitch << "," 
             << sensorData.pitch << ","
             << aircraft.roll << ","
             << flightStateToString(aircraft.flightState) << std::endl;
}

void logFlightEvent(const FlightEvent& event, int time)
{
    std::ofstream loadFile("event_log.csv", std::ios::app);

    // Log the flight number, time and event type
    loadFile << currentFlight << ","
             << time << ","
             << eventTypeToString(event.type) << ",";

    if (event.type == STATE_CHANGE)
    {
        loadFile << flightStateToString(event.previousState) << ","
                 << flightStateToString(event.currentState) << "," << std::endl;
    }

    else if (event.type == EXCESSIVE_PITCH)
    {
        loadFile << ",," << event.sensorValue << std::endl;
    }

    else if (event.type == PITCH_NORMAL)
    {
        // Same CSV layout as an excessive pitch event
        loadFile << ",," << event.sensorValue << std::endl;
    }
    
    else if (event.type == ALTITUDE_FAULT)
    {
        // Log the altitude measurement that triggered the fault
        loadFile << ",," << event.sensorValue << std::endl;
    }
    
}