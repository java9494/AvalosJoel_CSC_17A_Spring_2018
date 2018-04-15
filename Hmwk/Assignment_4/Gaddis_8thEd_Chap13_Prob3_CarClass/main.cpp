/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on April 4, 2018, 7:51 PM
 * Purpose: Create a template.
 */
 
 //System Libraries
#include <iostream>

#include "Car.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    Car myCar(2003, "Matrix");
    
    //Initialize Variables
    for (int count=0;count<5;count++){//Call accelerate function 5 times, display speed
        myCar.acc();
        cout<<myCar.getSpd()<<endl;
    }
    for (int count=0;count<5;count++){//Call accelerate function 5 times, display speed
        myCar.dec();
        cout<<myCar.getSpd()<<endl;
    }
    
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
    return 0;
}