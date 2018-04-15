/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on April 4, 2018, 8:42 PM
 * Purpose: Create a circle program utilizing a class.
 */
 
 //System Libraries
#include <iostream>

#include "Circle.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    float rad;
    cout<<"Circle Program"<<endl;
    cout<<"--------------"<<endl;
    cout<<"Enter in your circle's radius."<<endl;
    cin>>rad;
    Circle myCirc(rad);
    
    //Initialize Variables
    
    //Process/Map inputs to outputs
            
    //output data
    cout<<"Circle's Area: "<<myCirc.getArea()<<endl;
    cout<<"Circle's Diameter: "<<myCirc.getDiam()<<endl;
    cout<<"Circle's Circumference: "<<myCirc.getCir()<<endl;
            
    //Exit stage right!
    return 0;
}