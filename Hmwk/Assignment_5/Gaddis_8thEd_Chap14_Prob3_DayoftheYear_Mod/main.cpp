/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on May 6, 2018, 12:25 PM
 * Purpose: Create a program that will take an integer as a day of the year
 * and cout the month and day of that month that the integer represents
 * Mod: Add a constructor that takes 2 paramters
 */
 
 //System Libraries
#include <iostream>
#include "DayYear.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    string month;
    int date;
    cout<<"Hello! Enter in a month, then a number between 1-31, to output the day of the year that is."<<endl;
    cin>>month;
    cin>>date;
    DayYear day(month,date);
    cout<<"Day "<<day.getDate()<<"."<<endl;
    
    
    //Initialize Variables
    
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
    return 0;
}