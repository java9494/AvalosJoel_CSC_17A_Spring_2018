/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 24, 2018, 3:16 PM
 * Purpose: Create a corporate sales data program.
 */
 
 //System Libraries
#include <iostream>
#include <iomanip>

#include "DivInfo.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    DivInfo eastDiv,westDiv,nrthDiv,sthDiv;//East, West, North, and South divisions
    
    //Initialize Variables
    cout<<"Corporate Sales Program"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"Let's start with the East division."<<endl;
    cout<<"Please enter in the name."<<endl;
    getline(cin,eastDiv.divName);
    cout<<"Next, enter in each of the sales figures for each quarter."<<endl;
    cin>>eastDiv.frstQtr>>eastDiv.scndQtr>>eastDiv.thrdQtr>>eastDiv.frthQtr;
    cout<<"Now, enter the name of the West division."<<endl;
    cin.ignore();
    getline(cin,westDiv.divName);
    cout<<"Next, enter in each of the sales figures for each quarter."<<endl;
    cin>>westDiv.frstQtr>>westDiv.scndQtr>>westDiv.thrdQtr>>westDiv.frthQtr;
    cout<<"Now, enter the name of the South division."<<endl;
    cin.ignore();
    getline(cin,sthDiv.divName);
    cout<<"Next, enter in each of the sales figures for each quarter."<<endl;
    cin>>sthDiv.frstQtr>>sthDiv.scndQtr>>sthDiv.thrdQtr>>sthDiv.frthQtr; 
    cout<<"Finally, enter the name of the North division."<<endl;
    cin.ignore();
    getline(cin,nrthDiv.divName);
    cout<<"Next, enter in each of the sales figures for each quarter."<<endl;
    cin>>nrthDiv.frstQtr>>nrthDiv.scndQtr>>nrthDiv.thrdQtr>>nrthDiv.frthQtr; 
    
    //Process/Map inputs to outputs
    westDiv.ttlSale=westDiv.frstQtr+westDiv.scndQtr+westDiv.thrdQtr+westDiv.frthQtr;
    westDiv.avgQtr=westDiv.ttlSale/4.0f;
    eastDiv.ttlSale=eastDiv.frstQtr+eastDiv.scndQtr+eastDiv.thrdQtr+eastDiv.frthQtr;
    eastDiv.avgQtr=eastDiv.ttlSale/4.0f;
    sthDiv.ttlSale=sthDiv.frstQtr+sthDiv.scndQtr+sthDiv.thrdQtr+sthDiv.frthQtr;
    sthDiv.avgQtr=sthDiv.ttlSale/4.0f;
    nrthDiv.ttlSale=nrthDiv.frstQtr+nrthDiv.scndQtr+nrthDiv.thrdQtr+nrthDiv.frthQtr;
    nrthDiv.avgQtr=nrthDiv.ttlSale/4.0f;
    
    //output data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Corporate Sales Information:"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"East Division"<<endl;
    cout<<"-------------"<<endl;
    cout<<"1st Quarter Sales: $"<<eastDiv.frstQtr<<endl;
    cout<<"2nd Quarter Sales: $"<<eastDiv.scndQtr<<endl;
    cout<<"3rd Quarter Sales: $"<<eastDiv.thrdQtr<<endl;
    cout<<"4th Quarter Sales: $"<<eastDiv.frthQtr<<endl;
    cout<<"Total Sales: $"<<eastDiv.ttlSale<<endl;
    cout<<"Average Quarter Sales: $"<<eastDiv.avgQtr<<endl;
    cout<<"West Division"<<endl;
    cout<<"-------------"<<endl;
    cout<<"1st Quarter Sales: $"<<westDiv.frstQtr<<endl;
    cout<<"2nd Quarter Sales: $"<<westDiv.scndQtr<<endl;
    cout<<"3rd Quarter Sales: $"<<westDiv.thrdQtr<<endl;
    cout<<"4th Quarter Sales: $"<<westDiv.frthQtr<<endl;
    cout<<"Total Sales: $"<<westDiv.ttlSale<<endl;
    cout<<"Average Quarter Sales: $"<<westDiv.avgQtr<<endl;
    cout<<"South Division"<<endl;
    cout<<"-------------"<<endl;
    cout<<"1st Quarter Sales: $"<<sthDiv.frstQtr<<endl;
    cout<<"2nd Quarter Sales: $"<<sthDiv.scndQtr<<endl;
    cout<<"3rd Quarter Sales: $"<<sthDiv.thrdQtr<<endl;
    cout<<"4th Quarter Sales: $"<<sthDiv.frthQtr<<endl;
    cout<<"Total Sales: $"<<sthDiv.ttlSale<<endl;
    cout<<"Average Quarter Sales: $"<<sthDiv.avgQtr<<endl;
    cout<<"North Division"<<endl;
    cout<<"-------------"<<endl;
    cout<<"1st Quarter Sales: $"<<nrthDiv.frstQtr<<endl;
    cout<<"2nd Quarter Sales: $"<<nrthDiv.scndQtr<<endl;
    cout<<"3rd Quarter Sales: $"<<nrthDiv.thrdQtr<<endl;
    cout<<"4th Quarter Sales: $"<<nrthDiv.frthQtr<<endl;
    cout<<"Total Sales: $"<<nrthDiv.ttlSale<<endl;
    cout<<"Average Quarter Sales: $"<<nrthDiv.avgQtr<<endl;
            
    //Exit stage right!
    return 0;
}