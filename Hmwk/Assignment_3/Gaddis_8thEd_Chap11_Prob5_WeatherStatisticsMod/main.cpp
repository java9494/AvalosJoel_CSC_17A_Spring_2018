/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 13, 2018, 11:02 PM
 * Purpose: Create a program that uses a structure to store weather data.
 * This time, using an enumerated data type for each month.
 */
 
 //System Libraries
#include <iostream>

#include "WthrDta.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
enum Month {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};//Enumerated DT

//Function Prototypes
void getData(WthrDta [],const int,Month);
float mthRain(WthrDta [],const int,Month);
float ttRain(WthrDta [],const int,Month);
float avgMtmp(WthrDta [],const int,Month);
void hiLoTmp(WthrDta [],const int,Month);

//Execution Begins Here
int main(int argc, char** argv) {
   
    //Declare Variables
    const int MONTHS=12;//12 months in year
    //enum Month {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};//Enumerated DT
    WthrDta month[MONTHS];//Array of structures for each month
    Month mon;
    float avgMrn,//Average monthly rain
          avgTemp,//Average monthly temp
          annRain;//Total annual rainfall
    
    //Initialize Variables
    cout<<"Weather Data Program"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Enter in data for each month."<<endl;
    getData(month,MONTHS,mon);
    avgMrn=mthRain(month,MONTHS,mon);
    cout<<"-----------------------------------------"<<endl;
    cout<<"The average monthly rainfall was "<<avgMrn<<" inches of rain."<<endl;
    annRain=ttRain(month,MONTHS,mon);
    cout<<"The total annual rainfall was "<<annRain<<" inches of rain."<<endl;
    avgTemp=avgMtmp(month,MONTHS,mon);
    cout<<"The average monthly temperature was "<<avgTemp<<" degrees."<<endl;
    hiLoTmp(month,MONTHS,mon);
    
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
    return 0;
}

void getData(WthrDta month[],const int MONTHS,Month mon){
    for (mon=JAN;mon<=DEC;mon=static_cast<Month>(mon+1)){
        cout<<"Month "<<mon+1<<":\n";
        cout<<"-------"<<endl;
        cout<<"What was the total rainfall?"<<endl;
        cin>>month[mon].ttlRain;
        cout<<"What was the highest temperature?"<<endl;
        cin>>month[mon].hiTemp;
        cout<<"What was the lowest temperature?"<<endl;
        cin>>month[mon].lowTemp;
        cout<<"Finally, what was the average temperature?"<<endl;
        cin>>month[mon].avgTemp;
    }
}

float mthRain(WthrDta month[],const int MONTHS,Month mon){
    float mthRain=0;//Average monthly rainfall
    for (mon=JAN;mon<=DEC;mon=static_cast<Month>(mon+1)){
        mthRain+=month[mon].ttlRain;
    }
    mthRain/=12.0f;
    return mthRain;
}

float ttRain(WthrDta month[],const int MONTHS,Month mon){
    float ttlRain=0;
    for (mon=JAN;mon<=DEC;mon=static_cast<Month>(mon+1)){
        ttlRain+=month[mon].ttlRain;
    }
    return ttlRain;
}

float avgMtmp(WthrDta month[],const int MONTHS,Month mon){
    float avgTemp=0;//Average monthly temperature
    for (mon=JAN;mon<=DEC;mon=static_cast<Month>(mon+1)){
        avgTemp+=month[mon].avgTemp;
    }
    cout<<avgTemp<<endl;
    avgTemp/=12.0f;
    cout<<avgTemp<<endl;
    return avgTemp;
}

void hiLoTmp(WthrDta month[],const int MONTHS,Month mon){
    float hiTemp=month[0].hiTemp;//Highest temp
    float loTemp=month[0].lowTemp;//Lowest temp
    cout<<loTemp<<endl;
    int hTmpPos=0;//position of month with highest temp
    int lTmpPos=0;//position of month with lowest temp
    for (mon=JAN;mon<=DEC;mon=static_cast<Month>(mon+1)){
        if (month[mon+1].hiTemp>month[mon].hiTemp){
            hiTemp=month[mon+1].hiTemp;
            hTmpPos=mon+1;
        }
    }
    cout<<"The highest temperature of the year was "<<hiTemp<<" degrees.\n";
    cout<<"It occured in month "<<hTmpPos+1<<endl;
    for (mon=JAN;mon<=DEC;mon=static_cast<Month>(mon+1)){
        if (month[mon+1].lowTemp<month[mon].lowTemp){
            loTemp=month[mon+1].lowTemp;
            lTmpPos=mon+1;
            cout<<loTemp<<endl;
            cout<<lTmpPos<<endl;
        }
    }
    cout<<"The lowest temperature of the year was "<<loTemp<<" degrees.\n";
    cout<<"It occured in month "<<lTmpPos+1<<endl;
}