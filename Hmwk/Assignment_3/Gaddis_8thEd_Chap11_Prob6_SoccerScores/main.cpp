/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 24, 2018, 3:48 PM.
 * Purpose: Create a program that keeps track of a soccer team's info.
 */
 
 //System Libraries
#include <iostream>
#include <iomanip>

#include "SocInfo.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void info(SocInfo [],const int);
short ttlPts(SocInfo [],const int);
int maxPts(SocInfo [],const int);
void dsplay(SocInfo [],const int,short,int);

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    const int NUMPLY=12;//12 players on the team.
    short ttlPt;
    int posMax;//Position of player with max points.
    SocInfo player[NUMPLY];//Array of structures
    
    //Initialize Variables
    info(player,NUMPLY);
    
    //Process/Map inputs to outputs
    ttlPt=ttlPts(player,NUMPLY);
    posMax=maxPts(player,NUMPLY);
    
    //output data
    dsplay(player,NUMPLY,ttlPt,posMax);
            
    //Exit stage right!
    return 0;
}

void info(SocInfo player[], const int NUMPLY){
    cout<<"Soccer Team Data Program"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Welcome! Enter in the information for each player."<<endl;
    for (int count=0;count<NUMPLY;count++){
        cout<<"Enter in the name for player #"<<count+1<<endl;
        getline(cin,player[count].plyrNme);
        cout<<"Enter in "<<player[count].plyrNme<<"'s number."<<endl;
        cin>>player[count].plyrNum;
        if (player[count].plyrNum<0){
            cout<<"Error, cannot accept a negative value. Ending program...\n";
            exit(0);
        }
        cout<<"Enter in the points scored by "<<player[count].plyrNme<<endl;
        cin>>player[count].ptsScrd;
        if (player[count].ptsScrd<0){
            cout<<"Error, cannot accept a negative value. Ending program...\n";
            exit(0);
        }
        cin.ignore();       
    }
}

short ttlPts(SocInfo player[],const int NUMPLY){
    short ttlPts=0;
    for (int count=0;count<NUMPLY;count++){
        ttlPts+=player[count].ptsScrd;
    }
    return ttlPts;
}

int maxPts(SocInfo player[],const int NUMPLY){//Find person with most points
    short max=player[0].ptsScrd;
    int pos=0;
    for (int count=0;count<NUMPLY;count++){
        if (max<=player[count].ptsScrd){
            max=player[count].ptsScrd;
            pos=count;
            //cout<<pos<<endl;
        }
    }
    return pos;
}

void dsplay(SocInfo player[],const int NUMPLY,short ttl,int pos){
    cout<<"Soccer Team Information:"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Player "<<"     "<<"Number "<<"    "<<"Points Scored"<<endl;
    for (int count=0;count<NUMPLY;count++){
        cout<<player[count].plyrNme<<setw(10)<<" "<<player[count].plyrNum<<setw(10)<<" "<<player[count].ptsScrd<<endl;
    }
    cout<<"Total Points Scored by Team = "<<ttl<<" points."<<endl;
    cout<<"The person on the team who scored the most points was: "<<player[pos].plyrNme<<"."<<endl;
}