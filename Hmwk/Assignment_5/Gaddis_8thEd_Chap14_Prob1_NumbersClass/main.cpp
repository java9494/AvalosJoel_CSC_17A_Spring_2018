/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on May 6, 2018, 9:21 AM
 * Purpose: Create a program that translates whole dollar amounts (0-9999)
 * to an English description of that number.
 */
 
 //System Libraries
#include <iostream>
#include "Numbers.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    Numbers num;
    int n;
    cout<<"Hello, enter in a number you wish to convert to English."<<endl;
    cin>>n;
    num.setNum(n);
    num.print(num,n);
    //Initialize Variables
    
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
    return 0;
}