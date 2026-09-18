#ifndef FLIGHTCOMPUTER_H
#define FLIGHTCOMPUTER_H

#include "FlightData.h"

// Updates the aircraft's flight state using current flight using current sensor measurements
void updateFlightState(FlightData& aircraft, float measuredAltitude, float measuredPitch);

#endif