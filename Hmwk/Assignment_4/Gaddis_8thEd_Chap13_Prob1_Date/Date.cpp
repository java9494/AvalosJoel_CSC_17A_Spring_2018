/* 
 * File:   Date.cpp
 * Author: Joel Avalos
 * Created on March 31, 2018, 8:36 AM
 * Purpose: Date class specifications.
 */

#include <iostream>

#include "Date.h"
using namespace std;

Date::Date(){
    month=day=year=0;
}

void Date::setMnth(int m){
    if (m>=1&&m<=12)
        month=m;
    else {
        cout<<"Error, not a valid input. Ending program..."<<endl;
        exit(0);
    }
}

void Date::setDay(int d){
    if (d>=1&&d<=31)
        day=d;
    else {
        cout<<"Error, not a valid input. Ending program..."<<endl;
        exit(0);
    }
}

void Date::setYear(int y){
    year=y;
}

void Date::prnt1(int m, int d , int y){//Print date in  MM/DD/YYYY format
    if (m<10&&d<10)//Placing 0 if month is single digit, and 0 if date is single too
        cout<<"0"<<m<<"/0"<<d<<"/"<<y<<endl;
    else if (m<10&&d>10)
        cout<<"0"<<m<<"/"<<d<<"/"<<y<<endl;
    else if (m>10&&d<10)
        cout<<m<<"/0"<<d<<"/"<<y<<endl;
    else
        cout<<m<<d<<y<<endl;
}

void Date::prnt2(int m, int d , int y){//Print date in  Month Date, Year format
    string mnth1="January";
    string mnth2="February";
    string mnth3="March";
    string mnth4="April";
    string mnth5="May";
    string mnth6="June";
    string mnth7="July";
    string mnth8="August";
    string mnth9="September";
    string mnth10="October";
    string mnth11="November";
    string mnth12="December";
    
    if (m==1)
        cout<<mnth1;
    else if (m==2)
        cout<<mnth2;
    else if (m==3)
        cout<<mnth3;
    else if (m==4)
        cout<<mnth4;
    else if (m==5)
        cout<<mnth5;
    else if (m==6)
        cout<<mnth6;
    else if (m==7)
        cout<<mnth7;
    else if (m==8)
        cout<<mnth8;
    else if (m==9)
        cout<<mnth9;
    else if (m==10)
        cout<<mnth10;
    else if (m==11)
        cout<<mnth11;
    else
        cout<<mnth12;
    cout <<" "<<d<<", "<<y<<endl;
        
}

void Date::prnt3(int m, int d, int y){//Print date in Day Month Year format
    string mnth1="January";
    string mnth2="February";
    string mnth3="March";
    string mnth4="April";
    string mnth5="May";
    string mnth6="June";
    string mnth7="July";
    string mnth8="August";
    string mnth9="September";
    string mnth10="October";
    string mnth11="November";
    string mnth12="December";
    
    cout<<d<<" ";
    if (m==1)
        cout<<mnth1;
    else if (m==2)
        cout<<mnth2;
    else if (m==3)
        cout<<mnth3;
    else if (m==4)
        cout<<mnth4;
    else if (m==5)
        cout<<mnth5;
    else if (m==6)
        cout<<mnth6;
    else if (m==7)
        cout<<mnth7;
    else if (m==8)
        cout<<mnth8;
    else if (m==9)
        cout<<mnth9;
    else if (m==10)
        cout<<mnth10;
    else if (m==11)
        cout<<mnth11;
    else
        cout<<mnth12;
    cout<<" "<<y<<endl;
}

