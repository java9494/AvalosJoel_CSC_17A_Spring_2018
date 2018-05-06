/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on May 6, 2018, 1:33 PM
 * Purpose: Create a program to calculate .
 */
 
 //System Libraries
#include <iostream>

#include "NumDays.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    float numHrs,numHrs2;
    cout<<"Hello, enter in the number of hours worked. I will convert to a number of days."<<endl;
    cin>>numHrs;
    NumDays num(numHrs);
    num.setHr(numHrs);
    num.setDay(numHrs);
    cin>>numHrs2;
    NumDays num2(numHrs2);
    num2.setHr(numHrs2);
    num2.setDay(numHrs2);
    NumDays num3(0.0f);
    num3 = num + num2;
    num3.setDay(num3.getHr());
    
    
    //Initialize Variables
    cout<<num.getDay()<<" days."<<endl;
    cout<<num3.getDay()<<" days."<<endl;
    num3++;
    num3.setDay(num3.getHr());
    cout<<num3.getHr()<<endl;
    cout<<num3.getDay()<<" days."<<endl;
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
    return 0;
}