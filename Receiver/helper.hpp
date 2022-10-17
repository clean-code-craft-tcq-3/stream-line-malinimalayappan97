
#include <iostream> 
#include <vector>
using namespace std;

#define TOTAL_COUNT 5

struct sensorData
{
    vector<int> chargeRateList;
    vector<int> temperatureValueList;
};

struct sensorStatistics
{
    float chargeRateAvg;
    float tempAvg;
    int minChargeRate;
    int maxChargeRate;
    int minTemp;
    int maxTemp;
};

class sensorInterface
{
public:
     virtual sensorData getSensorDataFromConsole()=0;
};

class sensorReader: public sensorInterface
{
   public:
       sensorData sensorInterface()
       {
            sensorData data;
    	    string delimiter;
			std::string sensorInput;
            getline(cin, sensorInput);
            for(int sensorValue = 0; sensorValue < 5; sensorValue++)
            {
	        cin >> data.chargeRateList[sensorValue] >> delimiter >> data.temperatureValueList[sensorValue];
            }
            return data;
       }
};

class mockSensorReader: public sensorInterface
{
  public:
       int counter=0;
       sensorData mockData;

       sensorData getSensorDataFromConsole()
       {
            sensorData dataContainer;
            for(int sensorValue= 0; sensorValue< TOTAL_COUNT; sensorValue++)
            {
                
                   dataContainer.chargeRateList.push_back(mockData.chargeRateList[sensorValue]);
				   dataContainer.temperatureValueList.push_back(mockData.temperatureValueList[sensorValue]);
                 
            }
            return dataContainer;
      }
};

class displaySensorData
{
public:
     virtual void displayDataonConsole(sensorStatistics sensorValue)=0;
};

class sensorValuePrinter: public displaySensorData
{
   public:
       void displayDataonConsole(sensorStatistics stats)
       {
       	   cout<<endl;
       	   cout<<"*******Sensor Statistics*******"<<endl;
	   cout<<"\n"<<"Charge sensor average value : "<<to_string(stats.chargeRateAvg)<<endl;
    	   cout<<"Temperature sensor average value : "<<to_string(stats.tempAvg)<<endl;
    	   cout<<"Charge sensor minimum value : "<<to_string(stats.minChargeRate)<<endl;
    	   cout<<"Temperature sensor minimum value : "<<to_string(stats.minTemp)<<endl;
    	   cout<<"Charge sensor maximum value : "<<to_string(stats.maxChargeRate)<<endl;
    	   cout<<"Temperature sensor maximum value : "<<to_string(stats.maxTemp)<<endl;
	   cout<<"\n"<<"*******Sensor Statistics*******"<<endl;
      }
};


