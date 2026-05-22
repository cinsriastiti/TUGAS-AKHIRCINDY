// Sensor.h
#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

extern const byte nitro[];
extern const byte phos[];
extern const byte pota[];
extern const byte ec[];
extern const byte ph[];
extern const byte tempHum[];

extern const byte RE;
extern const byte DE;

float nitrogen();
float phosphorus();
float potassium();
uint16_t electricalConductivity();
float potentialHydrogen();
float humidity();
float temperature();

#endif // SENSOR_H