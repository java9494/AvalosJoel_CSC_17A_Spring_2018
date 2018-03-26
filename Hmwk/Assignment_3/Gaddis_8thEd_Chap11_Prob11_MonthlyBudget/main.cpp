/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 13, 2018, 10:34 AM
 * Purpose: Create a program that calculates monthly budget using a structure.
 */
 
 //System Libraries
#include <iostream>
#include <iomanip>

#include "MnthBgt.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
MnthBgt budget(MnthBgt);
void dsplay(MnthBgt,MnthBgt);

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    MnthBgt bills = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00,
            150.00, 75.00, 50.00};
    MnthBgt month;
    
    //Initialize Variables  
    month=budget(bills);
    
    //Process/Map inputs to outputs
    dsplay(bills,month);
            
    //output data
            
    //Exit stage right!
    return 0;
}

MnthBgt budget(MnthBgt month){
    MnthBgt temp;
    cout<<"Monthly Budget Calculator"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Please enter in the amount you spent this month on:"<<endl;
    cout<<"Housing."<<endl;
    cin>>temp.hsing;
    cout<<"Utilities."<<endl;
    cin>>temp.utility;
    cout<<"Housing Expenses."<<endl;
    cin>>temp.hseStuf;
    cout<<"Transportation."<<endl;
    cin>>temp.trnsprt;
    cout<<"Food."<<endl;
    cin>>temp.food;
    cout<<"Medical Expenses."<<endl;
    cin>>temp.medic;
    cout<<"Insurance."<<endl;
    cin>>temp.insrnce;
    cout<<"Entertainment."<<endl;
    cin>>temp.entrtn;
    cout<<"Clothes."<<endl;
    cin>>temp.clothes;
    cout<<"Any miscellaneous items."<<endl;
    cin>>temp.misc;
    
    return temp;
}

void dsplay(MnthBgt bills,MnthBgt spent){
    float ttlBdgt=1420.00;
    float mthCost=spent.hsing+spent.utility+spent.hseStuf+spent.trnsprt+spent.food+spent.medic+spent.insrnce+spent.entrtn+spent.clothes+spent.misc;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Bill"<<setw(10)<<" "<<"Amount Over/Under"<<endl;
    cout<<"----"<<setw(10)<<" "<<"-----------------"<<endl;
    cout<<"Housing:         "<<setw(10)<<" "<<"$"<<bills.hsing-spent.hsing<<endl;
    cout<<"Utilities:       "<<setw(10)<<" "<<"$"<<bills.utility-spent.utility<<endl;
    cout<<"House Expenses:  "<<setw(10)<<" "<<"$"<<bills.hseStuf-spent.hseStuf<<endl;
    cout<<"Transportation:  "<<setw(10)<<" "<<"$"<<bills.trnsprt-spent.trnsprt<<endl;
    cout<<"Food:            "<<setw(10)<<" "<<"$"<<bills.food-spent.food<<endl;
    cout<<"Medical Expenses:"<<setw(10)<<" "<<"$"<<bills.medic-spent.medic<<endl;
    cout<<"Insurance:       "<<setw(10)<<" "<<"$"<<bills.insrnce-spent.insrnce<<endl;
    cout<<"Entertainment:   "<<setw(10)<<" "<<"$"<<bills.entrtn-spent.entrtn<<endl;
    cout<<"Clothes:         "<<setw(10)<<" "<<"$"<<bills.clothes-spent.clothes<<endl;
    cout<<"Miscellaneous:   "<<setw(10)<<" "<<"$"<<bills.misc-spent.misc<<endl;
    cout<<"Total Over/Under:"<<setw(10)<<" "<<"$"<<ttlBdgt-mthCost<<endl;
}