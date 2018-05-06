/* 
 * File:   DayYear.cpp
 * Author: Joel Avalos
 * Purpose: Defining class functions and static members
 * Created on May 6, 2018, 11:13 AM
 */

#include <iostream>
#include <cstdlib>
#include "DyYear.h"

using namespace std;

string DyYear::month[12]={"January","February","March","April","May","June",
                           "July","August","September","October","November","December"};

DyYear::DyYear(string month, int day){
    if (month=="January"){
        if (day>31){
            cout<<"Not an appropriate day entered. Exiting program..."<<endl;
            exit(0);
        }
        else
            date=day;
    }
    if (month=="February"){
        if (day>28){
            cout<<"Not an appropriate day entered. Exiting program..."<<endl;
            exit(0);
        }
        else
            date=day+31;
    }
    if (month=="March"){
        if (day>31){
            cout<<"Not an appropriate day entered. Exiting program..."<<endl;
            exit(0);
        }
        else
            date=day+59;
    }
    if (month=="April"){
        if (day>30){
            cout<<"Not an appropriate day entered. Exiting program..."<<endl;
            exit(0);
        }
        else
            date=day+90;
    }
    if (month=="May"){
        if (day>31){
            cout<<"Not an appropriate day entered. Exiting program..."<<endl;
            exit(0);
        }
        else
            date=day+120;
    }
    if (month=="June"){
        if (day>30){
            cout<<"Not an appropriate day entered. Exiting program..."<<endl;
            exit(0);
        }
        else
            date=day+151;
    }
    if (month=="July"){
        if (day>31){
            cout<<"Not an appropriate day entered. Exiting program..."<<endl;
            exit(0);
        }
        else
            date=day+181;
    }
    if (month=="August"){
        if (day>31){
            cout<<"Not an appropriate day entered. Exiting program..."<<endl;
            exit(0);
        }
        else
            date=day+212;
    }
    if (month=="September"){
        if (day>30){
            cout<<"Not an appropriate day entered. Exiting program..."<<endl;
            exit(0);
        }
        else
            date=day+243;
    }
    if (month=="October"){
        if (day>31){
            cout<<"Not an appropriate day entered. Exiting program..."<<endl;
            exit(0);
        }
        else
            date=day+273;
    }
    if (month=="November"){
        if (day>31){
            cout<<"Not an appropriate day entered. Exiting program..."<<endl;
            exit(0);
        }
        else
            date=day+304;
    }
    if (month=="December"){
        if (day>31){
            cout<<"Not an appropriate day entered. Exiting program..."<<endl;
            exit(0);
        }
        else
            date=day+334;
    }
}
void DyYear::setDate(DyYear day,int d){
    while (d<=0||d>365){
        cout<<"Error, please enter a valid day (1-365)"<<endl;
        cin>>d;
    }
    day.date=d;
}
void DyYear::print(DyYear day, int d){
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

DyYear DyYear::operator ++(int){//Post-fix ++
    date++;
    simplfy();  
}

DyYear DyYear::operator --(int){//Post-fix --
    date--;
    simplfy();
}

void DyYear::simplfy(){
    if (date>365){//If modifying the day goes over 365
        date=1;
    }
    else if (date<=0){//if modifying the day goes below 1
        date=365;
    }
}