#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

_Bool CheckChargeRateInRange(float chargeRate);
_Bool CheckTempInRange(float temperature);
void PrintOnConsole(float temperature, float chargerate);
void Main(float* sensor_temprature,float* sensor_chargerate,int sensordatalength,float temp_min,float temp_max,float chargerate_min,float chargerate_max);