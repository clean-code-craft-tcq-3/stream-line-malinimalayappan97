#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "ProcessSensorData.h"

TEST_CASE("process input sensors value and send to receiver") {
  int sensordatalen = 8;
   float TempArray[sensordatalen] ={2,3, 3, 5, 4, 10, 11, 12};
   int ChargerateArray[sensordatalen] ={2,3, 3, 5, 4, 10, 11, 12};

   REQUIRE(Main(TempArray,ChargerateArray,sensordatalen,3,10,5,11) == 1);
   
}
