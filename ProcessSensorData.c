#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float chargerate_minvalue = 0.79;
float chargerate_maxvalue = 0.85;
float temp_minvalue       = 0.0; /*in Farenheit*/
float temp_maxvalue       = 45.0;/*in Farenheit*/

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

 float GetTempInFarenheit(float temperature,char tempunit)
  {
      float temp;
      if(tempunit == 'C')
      {
          temp = ((temperature * 9/5) + 32);
      }
      else
      {
          temp = temperature;
      }
      return temp;
  }
void PrintOnConsole(float temperature, float chargerate)
{
    printf("temp-%f,chargerate-%f\n", temperature, chargerate);
}

