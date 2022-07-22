#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "Receiver/helper.hpp"

TEST_CASE("Test the computation of Simple Moving Average")
{
		vector<int> sensorValueList={10,30,20,20,45,25,70,30,70,35};
		float avg=getAvg(sensorValueList,5);
        REQUIRE(avg==46.000000);
}

TEST_CASE("Test the computation of minimum value in the sensor data list")
{
        vector<int> sensorValueList={10,30,20,30,45,25,70,30,70,35};
		int min=getMinValue(sensorValueList);
        REQUIRE(min==10);
}

TEST_CASE("Test the computation of minimum value in the sensor data list where the list contains single element")
{
        vector<int> sensorValueList={20};
        int min=getMinValue(sensorValueList);
        REQUIRE(minValue==20);
}

TEST_CASE("Test the computation of maximum value in the sensor data list")
{ 
        vector<int> sensorValueList={10,30,20,40,45,25,70,30,70,35};
        int max=getMaxValue(sensorValueList);
        REQUIRE(maxValue==70);
}

TEST_CASE("Test functionality to read Sensor data from Console using mock functionality")
{
        sensorData mockSensorData;
        mockSensorData.chargeRateList={100,30,20,20,45,25,70,30,90,25};
        mockSensorData.temperatureValueList={60,80,20,30,45,10,70,40,70,50};
        sensorReader dataReader;
        dataReader.mockSensorData=mockSensorData;
        sensorData receivedSensorData=dataReader.readSensorDataFromConsole();
        REQUIRE(receivedSensorData.chargeRateList==mockSensorData.chargeRateList);
        REQUIRE(receivedSensorData.temperatureValueList==mockSensorData.temperatureValueList);
}

TEST_CASE("Test the Sensor Value Statistics obtained")
{
        sensorData mockSensorValue;
        mockSensorValue.chargeRateList={100,30,20,20,45,25,70,30,90,35};
        mockSensorValue.temperatureValueList={60,80,20,30,45,10,70,40,90,50};
        sensorReader dataReader;
        dataReader.mockSensorData=mockSensorValue;
        mockPrinter dataPrinterObject;
        sensorStatistics sensorDataStats=getSensorValueStatis(dataReader,dataPrinterObject); 
		REQUIRE(sensorDataStats.chargeRateAvg==50.000000);  
  		REQUIRE(sensorDataStats.tempAvg==52.000000);
		REQUIRE(sensorDataStats.minChargeRate==20);
    	REQUIRE(sensorDataStats.minTemp==10);
    	REQUIRE(sensorDataStats.maxChargeRate==100);
    	REQUIRE(sensorDataStats.maxTemp==90);
}