/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 24, 2018, 3:48 PM.
 * Purpose: Create a program that keeps track of a soccer team's info.
 */
 
 //System Libraries
#include <iostream>

#include "SocInfo.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void info(SocInfo [],const int);
void dsplay(SocInfo [],const int);

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    const int NUMPLY=12;//12 players on the team.
    SocInfo player[NUMPLY];
    
    //Initialize Variables
    cout<<"Soccer Team Data Program"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Welcome! Enter in the information for each player."<<endl;
    info(player,NUMPLY);
    
    //Process/Map inputs to outputs
    
    //output data
    cout<<"Soccer Team Information:"<<endl;
    cout<<"------------------------"<<endl;
    dsplay(player,NUMPLY);
            
    //Exit stage right!
    return 0;
}

void info(SocInfo player[], const int NUMPLY){
    for (int count=0;count<NUMPLY;count++){
        cout<<"Enter in the name for player #"<<count+1<<endl;
        getline(cin,player[count].plyrNme);
        cout<<"Enter in "<<player[count].plyrNme<<"'s number."<<endl;
        cin>>player[count].plyrNum;
        if (player[count].plyrNum<0){
            cout<<"Error, cannot accept a negative value. Ending program...\n";
            exit;
        }
        cout<<"Enter in the points scored by "<<player[count].plyrNme<<endl;
        cin>>player[count].ptsScrd;
        if (player[count].ptsScrd<0){
            cout<<"Error, cannot accept a negative value. Ending program...\n";
            exit;
        }
        cin.ignore();       
    }
}

void dsplay(SocInfo player[],const int NUMPLY){
    cout<<"Player "<<"     "<<"Number "<<"      "<<"Points Scored"<<endl;
    for (int count=0;count<NUMPLY;count++){
        cout<<player[count].plyrNme<<" "<<player[count].plyrNum<<" "<<player[count].ptsScrd<<endl;
    }
}