/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 31, 2018, 9:49 AM
 * Purpose: Create a program using a created Employee class.
 */
 
 //System Libraries
#include <iostream>

#include "Emplyee.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    Emplyee emp1("Susan Meyers",47899,"Accounting","Vice President");
    Emplyee emp2("Mark Jones",39119,"IT","Programmer");
    Emplyee emp3("Joy Rogers",81774,"Manufacturing","Engineer");          
            
    //Initialize Variables
    
    //Process/Map inputs to outputs
            
    //output data
    cout<<emp1.getName()<<" "<<emp1.getID()<<" "<<emp1.getDpt()<<" "<<emp1.getPos()<<endl;
    cout<<emp2.getName()<<" "<<emp2.getID()<<" "<<emp2.getDpt()<<" "<<emp2.getPos()<<endl;
    cout<<emp3.getName()<<" "<<emp3.getID()<<" "<<emp3.getDpt()<<" "<<emp3.getPos()<<endl;
            
    //Exit stage right!
    return 0;
}