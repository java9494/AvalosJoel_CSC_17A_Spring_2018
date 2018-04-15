/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on April 4, 2018, 8:14 PM
 * Purpose: Create a personal information class.
 */
 
 //System Libraries
#include <iostream>

#include "PerInfo.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    PerInfo myInfo("Joel Avalos","23","20338 Lyon Road","(909) 452-1952");
    PerInfo rndmI("John Doe","55","1234 Happy Road","(123) 456-7890");
    PerInfo rndmII("Jane Doe","99","1234 Happy Road","(789) 456-123");
    
    //Initialize Variables
    
    //Process/Map inputs to outputs
            
    //output data
    cout<<myInfo.getName()<<endl;
    cout<<myInfo.getAge()<<endl;
    cout<<myInfo.getAdd()<<endl;
    cout<<myInfo.getFone()<<endl;
    cout<<rndmI.getName()<<endl;
    cout<<rndmI.getAge()<<endl;
    cout<<rndmI.getAdd()<<endl;
    cout<<rndmI.getFone()<<endl;
    cout<<rndmII.getName()<<endl;
    cout<<rndmII.getAge()<<endl;
    cout<<rndmII.getAdd()<<endl;
    cout<<rndmII.getFone()<<endl;
    
            
    //Exit stage right!
    return 0;
}