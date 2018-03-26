/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 13, 2018, 11:02 PM
 * Purpose: Create a program that uses a structure to store weather data.
 */
 
 //System Libraries
#include <iostream>

#include "WthrDta.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void getData(WthrDta [],const int);
float mthRain(WthrDta [],const int);
float ttRain(WthrDta [],const int);
float avgMtmp(WthrDta [],const int);
void hiLoTmp(WthrDta [],const int);

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    const int MONTHS=12;//12 months in year
    WthrDta month[MONTHS];//Array of structures for each month
    float avgMrn,//Average monthly rain
          avgTemp,//Average monthly temp
          annRain;//Total annual rainfall
    
    //Initialize Variables
    cout<<"Weather Data Program"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Enter in data for each month."<<endl;
    getData(month,MONTHS);
    avgMrn=mthRain(month,MONTHS);
    cout<<"-----------------------------------------"<<endl;
    cout<<"The average monthly rainfall was "<<avgMrn<<" inches of rain."<<endl;
    annRain=ttRain(month,MONTHS);
    cout<<"The total annual rainfall was "<<annRain<<" inches of rain."<<endl;
    avgTemp=avgMtmp(month,MONTHS);
    cout<<"The average monthly temperature was "<<avgTemp<<" degrees."<<endl;
    hiLoTmp(month,MONTHS);
    
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
    return 0;
}

void getData(WthrDta month[],const int MONTHS){
    for (int count=0;count<MONTHS;count++){
        cout<<"Month "<<count+1<<":\n";
        cout<<"-------"<<endl;
        cout<<"What was the total rainfall?"<<endl;
        cin>>month[count].ttlRain;
        cout<<"What was the highest temperature?"<<endl;
        cin>>month[count].hiTemp;
        cout<<"What was the lowest temperature?"<<endl;
        cin>>month[count].lowTemp;
        cout<<"Finally, what was the average temperature?"<<endl;
        cin>>month[count].avgTemp;
    }
}

float mthRain(WthrDta month[],const int MONTHS){
    float mthRain=0;//Average monthly rainfall
    for (int count=0;count<MONTHS;count++){
        mthRain+=month[count].ttlRain;
    }
    mthRain/=12.0f;
    return mthRain;
}

float ttRain(WthrDta month[],const int MONTHS){
    float ttlRain=0;
    for (int count=0;count<MONTHS;count++){
        ttlRain+=month[count].ttlRain;
    }
    return ttlRain;
}

float avgMtmp(WthrDta month[],const int MONTHS){
    float avgTemp=0;//Average monthly temperature
    for (int count=0;count<MONTHS;count++){
        avgTemp+=month[count].avgTemp;
    }
    cout<<avgTemp<<endl;
    avgTemp/=12.0f;
    cout<<avgTemp<<endl;
    return avgTemp;
}

void hiLoTmp(WthrDta month[],const int MONTHS){
    float hiTemp=month[0].hiTemp;//Highest temp
    float loTemp=month[0].lowTemp;//Lowest temp
    int hTmpPos=0;//position of month with highest temp
    int lTmpPos=0;//position of month with lowest temp
    for (int count=0;count<MONTHS-1;count++){
        if (month[count+1].hiTemp>month[count].hiTemp){
            hiTemp=month[count+1].hiTemp;
            hTmpPos=count+1;
        }
    }
    cout<<"The highest temperature of the year was "<<hiTemp<<" degrees.\n";
    cout<<"It occured in month "<<hTmpPos+1<<endl;
    for (int count=0;count<MONTHS-1;count++){
        if (month[count+1].lowTemp<month[count].lowTemp){
            loTemp=month[count+1].lowTemp;
            lTmpPos=count+1;
        }
    }
    cout<<"The lowest temperature of the year was "<<loTemp<<" degrees.\n";
    cout<<"It occured in month "<<lTmpPos+1<<endl;
}