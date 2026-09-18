#ifndef DATALOGGER_H
#define DATALOGGER_H

#include "FlightData.h"
#include "FlightEvent.h"

void initializeLog();

// Logs the aircraft data and sensor measurements to the flight log
void logFlightData(
    const FlightData& aircraft, 
    int time, 
    float measuredAltitude, 
    float measuredPitch);

// logs a change in the aircraft's flight state
void logFlightEvent(const FlightEvent& event, int time);
#endif