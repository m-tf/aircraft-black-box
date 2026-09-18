#ifndef FLIGHTCOMPUTER_H
#define FLIGHTCOMPUTER_H

#include "FlightData.h"

// Updates the aircraft's flight state using current flight and sensor data
void updateFlightState(FlightData& aircraft, float measuredAltitude);

#endif