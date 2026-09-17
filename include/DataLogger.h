#ifndef DATALOGGER_H
#define DATALOGGER_H

#include "FlightData.h"

void initializeLog();

void logFlightData(const FlightData& aircraft, int time);

#endif