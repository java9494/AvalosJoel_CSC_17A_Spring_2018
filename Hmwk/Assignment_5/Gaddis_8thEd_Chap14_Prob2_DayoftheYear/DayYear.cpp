/* 
 * File:   DayYear.cpp
 * Author: Joel Avalos
 * Purpose: Defining class functions and static members
 * Created on May 6, 2018, 11:13 AM
 */

#include <iostream>
#include "DayYear.h"

using namespace std;

string DayYear::month[12]={"January","February","March","April","May","June",
                           "July","August","September","October","November","December"};

void DayYear::setDate(DayYear day,int d){
    while (d<=0||d>365){
        cout<<"Error, please enter a valid day (1-365)"<<endl;
        cin>>d;
    }
    day.date=d;
}

void DayYear::print(DayYear day, int d){
    int month;
    if (d<=31){//january
        month=0;
        cout<<day.getMnth(month)<<" "<<d<<"."<<endl;
    }
    else if (d>31&&d<=59){//February
        month=1;
        cout<<day.getMnth(month)<<" "<<d-31<<"."<<endl;
    }
    else if (d>59&&d<=90){//march
        month=2;
        cout<<day.getMnth(month)<<" "<<d-59<<"."<<endl;
    }
    else if (d>90&&d<=120){//april
        month=3;
        cout<<day.getMnth(month)<<" "<<d-90<<"."<<endl;
    }
    else if (d>120&&d<=151){//May
        month=4;
        cout<<day.getMnth(month)<<" "<<d-120<<"."<<endl;
    }
    else if (d>151&&d<=181){//June
        month=5;
        cout<<day.getMnth(month)<<" "<<d-151<<"."<<endl;
    }
    else if (d>181&&d<=212){//July
        month=6;
        cout<<day.getMnth(month)<<" "<<d-181<<"."<<endl;
    }
    else if (d>212&&d<=243){//August
        month=7;
        cout<<day.getMnth(month)<<" "<<d-212<<"."<<endl;
    }
    else if (d>243&&d<=273){//Sep
        month=8;
        cout<<day.getMnth(month)<<" "<<d-243<<"."<<endl;
    }
    else if (d>273&&d<=304){//Oct
        month=9;
        cout<<day.getMnth(month)<<" "<<d-273<<"."<<endl;
    }
    else if (d>304&&d<=334){//Nov
        month=10;
        cout<<day.getMnth(month)<<" "<<d-304<<"."<<endl;
    }
    else {//Dec
        month=11;
        cout<<day.getMnth(month)<<" "<<d-334<<"."<<endl;
    }
}


