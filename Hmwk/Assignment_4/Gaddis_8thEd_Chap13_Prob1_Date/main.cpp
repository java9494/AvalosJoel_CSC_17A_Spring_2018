/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 31, 2018, 8:35 AM
 * Purpose: Create a class that represents the date.
 */
 
 //System Libraries
#include <iostream>

#include "Date.h"
//#include "Date.cpp"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    Date date;
    int m,d,y;//User inputted values for month, date, year.
    cout<<"Date Formatting Program"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"Hello! Enter in a date of your choosing, and I will format it \n"
        <<"in three different ways."<<endl;
    cout<<"What is the date?"<<endl;
    cin>>d;
    cout<<"What is the month?"<<endl;
    cin>>m;
    cout<<"What is the year?"<<endl;
    cin>>y;
    
    //Initialize Variables
    date.setDay(d);
    date.setMnth(m);
    date.setYear(y);
    
    //Process/Map inputs to outputs
    date.prnt1(m,d,y);
    date.prnt2(m,d,y);
    date.prnt3(m,d,y);
            
    //output data
            
    //Exit stage right!
    return 0;
}