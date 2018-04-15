/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on April 4, 2018, 8:29 PM
 * Purpose: Create a Retail Item class.
 */
 
 //System Libraries
#include <iostream>

#include "RetItem.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    RetItem item1("Jacket",12,59.95f);
    RetItem item2("Designer Jeans",40,34.95f);
    RetItem item3("Shirt",20,24.95f);
    
    //Initialize Variables
    
    //Process/Map inputs to outputs
            
    //output data
    cout<<"         "<<"Description"<<"      "<<"Units On Hand"<<"     "<<"Price"<<endl;
    cout<<"Item 1   "<<item1.getDesc()<<"                "<<item1.getHand()<<"           "<<item1.getPrce()<<endl;
    cout<<"Item 2   "<<item2.getDesc()<<"        "<<item2.getHand()<<"           "<<item2.getPrce()<<endl;
    cout<<"Item 3   "<<item3.getDesc()<<"                 "<<item3.getHand()<<"           "<<item3.getPrce()<<endl;
            
    //Exit stage right!
    return 0;
}