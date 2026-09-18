#include "DataLogger.h"

#include <fstream>
#include <string>


int currentFlight = 0;

void initializeLog() {
    std::ifstream readFile("flight_log.csv");

    if (!readFile.is_open())
    {
        // no previous log
        currentFlight = 1;
        std::ofstream loadFile("flight_log.csv");
        loadFile << "flight,time,altitude,speed,pitch,roll,state" << std::endl;
    }
    else {
        // previous log exists
        // read and figure out last flight number
        std::string line;

        // read one line here to skip the header
        std::getline(readFile, line);

        int lastFlight = 0;

        while (std::getline(readFile, line))
        {
            std::size_t firstComma = line.find(',');               // find first comma
            std::string flightNumber = line.substr(0, firstComma); // gets "1" (hopefully)
            lastFlight = std::stoi(flightNumber);              // converts "1" -> 1
        }
        currentFlight = lastFlight + 1;
        

    }
    
    
}

void logFlightData(const FlightData& aircraft, int time) {

    std::ofstream loadFile("flight_log.csv", std::ios::app);

    loadFile << currentFlight << ","
             << time << ","
             << aircraft.altitude << ","
             << aircraft.speed << ","
             << aircraft.pitch << "," 
             << aircraft.roll << ","
             << flightStateToString(aircraft.flightState) << std::endl;
}