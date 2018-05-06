/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on May 6, 2018, 3:10 PM
 * Purpose: Create a program to calculate time off for an employee.
 */
 
 //System Libraries
#include <iostream>

#include "NumDays.h"
#include "TimeOff.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    float numHrs;
    cout<<"Hello, enter in the number of hours worked. I will convert to a number of days."<<endl;
    cin>>numHrs;
    NumDays num(numHrs);
    num.setHr(numHrs);
    num.setDay(numHrs);
    TimeOff emp;
    emp.setMxS(num);
    emp.setMxV(num);
    
    //Initialize Variables
    cout<<num.getDay()<<" days."<<endl;
    cout<<emp.getMxS()<<" hours of sick leave."<<endl;
    cout<<emp.getMxV()<<" hours of paid vacation leave."<<endl;
    
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
    return 0;
}