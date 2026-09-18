#include "DataLogger.h"

#include <fstream>
#include <string>


int currentFlight = 0;

void initializeLog() {
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

    std::ifstream eventReadFile("event_log.csv");
    if (!eventReadFile.is_open())
    {
        // No previous log
        std::ofstream eventFile("event_log.csv");

        // Create the CSV header
        eventFile << "flight,time,previous_state,current_state" << std::endl;
    }

    
    
    
}

void logFlightData(const FlightData& aircraft, int time, float measuredAltitude, float measuredPitch) {

    std::ofstream loadFile("flight_log.csv", std::ios::app);

    loadFile << currentFlight << ","
             << time << ","
             << aircraft.altitude << ","
             << measuredAltitude << ","
             << aircraft.speed << ","
             << aircraft.pitch << "," 
             << measuredPitch << ","
             << aircraft.roll << ","
             << flightStateToString(aircraft.flightState) << std::endl;
}

void logFlightEvent(const FlightEvent& event, int time)
{
    std::ofstream loadFile("event_log.csv", std::ios::app);

    loadFile << currentFlight << ","
             << time << ","
             << flightStateToString(event.previousState) << ","
             << flightStateToString(event.currentState) << std::endl;
}