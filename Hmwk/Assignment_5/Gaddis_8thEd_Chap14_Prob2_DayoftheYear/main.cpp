/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on May 6, 2018, 10:59 AM
 * Purpose: Create a program that will take an integer as a day of the year
 * and cout the month and day of that month that the integer represents
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
    DayYear day;
    int numb;
    cout<<"Hello! Please enter in the day of the year that you wish to translate into Month Day format."<<endl;
    cin>>numb;
    day.setDate(day,numb);
    day.print(day,numb);
    
    
    //Initialize Variables
    
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
    return 0;
}