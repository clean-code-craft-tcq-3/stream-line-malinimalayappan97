#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Sender.h"
#include "Sender.c"

TEST_CASE("process input sensors value and send to receiver") {
  
  BMSData_s sensorData_s;

  sensorData_s.chargeRate_minvalue = 0;
  sensorData_s.chargeRate_maxvalue = 100;
  sensorData_s.temp_minvalue = 0;
  sensorData_s.temp_maxvalue = 75;
  sensorData_s.totalNoofValues = 50;
  
  Main(sensorData_s);  
}
