#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

float chargerate_minvalue ;
float chargerate_maxvalue ;
float temp_minvalue; 
float temp_maxvalue ;
_Bool isChargeRateValid ;
_Bool isTempValid ;

_Bool CheckChargeRateInRange(float chargeRate)
  {
      if(chargeRate < chargerate_minvalue|| chargeRate > chargerate_maxvalue)
      {
          return 0;
      }
      else
      {
        return 1;  
      }
  }
_Bool CheckTempInRange(float temperature)
  {
      if(temperature < temp_minvalue|| temperature > temp_maxvalue)
      {
          return 0;
      }
      else
      {
        return 1;  
      }
  }

void PrintOnConsole(float temperature, float chargerate)
{
   if((isChargeRateValid == 0) &&(isTempValid == 0))
      {
          printf("temp-%f,chargerate-%f\n", temperature, chargerate);
      }
}
void Main(float* sensor_temprature,float* sensor_chargerate,int sensordatalength,float temp_min,float temp_max,float chargerate_min,float chargerate_max)
{ 
  float chargeRate[sensordatalength];
  float temperature[sensordatalength];
  chargerate_minvalue = chargerate_min;
  chargerate_maxvalue = chargerate_max;
  temp_minvalue = temp_min; 
  temp_maxvalue = temp_max;
  
  memcpy(chargeRate,sensor_chargerate,sensordatalength);
  memcpy(temperature,sensor_temprature,sensordatalength);
  
  for(int data = 0; data < sensordatalength ; data ++)
  {
      isChargeRateValid = CheckChargeRateInRange(chargeRate[data]);
      isTempValid = CheckTempInRange(temperature[data]);
      PrintOnConsole(temperature[data], chargeRate[data]);
  }
  
  
}

