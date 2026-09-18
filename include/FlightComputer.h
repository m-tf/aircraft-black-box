#ifndef FLIGHTCOMPUTER_H
#define FLIGHTCOMPUTER_H

#include "FlightData.h"
#include "SensorData.h"

// Updates the aircraft's flight state using current sensor measurements
void updateFlightState(FlightData& aircraft, const SensorData& sensorData);

#endif