#include <algorithm>
#include "helper.hpp"

float getAvg(vector<int> sensorValueList, int noOfEntries)
{
    float total = 0;
    for(int sensorDataItr = TOTAL_COUNT-noOfEntries; sensorDataItr < TOTAL_COUNT; sensorDataItr++)
    {
        total += sensorValueList[sensorDataItr];
    }
    return (total/noOfEntries);
}

int getMinValue(vector<int> sensorValueList)
{
    return *min_element(sensorValueList.begin(),sensorValueList.end());
}

int getMaxValue(vector<int> sensorValueList)
{
    return *max_element(sensorValueList.begin(),sensorValueList.end());
}

/*sensorStatistics compute(sensorData value)
{
    sensorStatistics stats;
    stats.chargeRateAvg = getAvg(value.chargeRateList, TOTAL_COUNT);
    stats.tempAvg = getAvg(value.temperatureValueList, TOTAL_COUNT);
    stats.minChargeRate = getMinValue(value.chargeRateList);
    stats.minTemp = getMinValue(value.temperatureValueList);
    stats.maxChargeRate = getMaxValue(value.chargeRateList);
    stats.maxTemp = getMaxValue(value.temperatureValueList);
    return stats;
}

sensorStatistics getSensorValueStatis(sensorInterface &dataReader,displaySensorData &sensorDataPrinter)
{
    sensorData sensorValue=dataReader.getSensorDataFromConsole();
    sensorStatistics sensorDataStats;
    if(!sensorValue.chargeRateList.empty() && !sensorValue.temperatureValueList.empty())
    {
    	sensorDataStats=compute(sensorValue);
    	sensorDataPrinter.displayDataonConsole(sensorDataStats);
    }
    return sensorDataStats;
}*/
