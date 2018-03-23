/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 23, 2018, 1:29 PM
 * Purpose: Create a program that uses a structure to store movie info
 */
 
 //System Libraries
#include <iostream>

#include "MovData.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void dsplyMv(MovData,MovData);

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    MovData Movie1,Movie2;//Initializing two MovData variables.
    
    //Initialize Variables
    Movie1.title="AdventureLand";
    Movie1.runTime="107 minutes.";
    Movie1.directr="Greg Mottola";
    Movie1.yearRls="2009";
    Movie1.prodCst="9.8 million USD";
    Movie1.yr1prft="$16,044,025 USD.";
    Movie2.title="Solaris";
    Movie2.directr="Andrei Tarkovsky";
    Movie2.yearRls="1972";
    Movie2.runTime="166 minutes.";
    Movie2.prodCst="1 million Soviet Rubels (equivalent to $829k in 1972.)";        
    Movie2.yr1prft="Unable to find data.";
    //Process/Map inputs to outputs
            
    //output data
    dsplyMv(Movie1,Movie2);
            
    //Exit stage right!
    return 0;
}
void dsplyMv(MovData a, MovData b){
    cout<<"Movie 1:\n"
        <<"-------\n"
        <<a.title<<"\n"
        <<"Directed by "<<a.directr<<"\n"
        <<"Released "<<a.yearRls<<"\n"
        <<"Run Time: "<<a.runTime<<"\n"
        <<"Production Cost: "<<a.prodCst<<"\n"
        <<"First Year Profit: "<<a.yr1prft<<endl;
    
    cout<<"Movie 2:\n"
        <<"-------\n"
        <<b.title<<"\n"
        <<"Directed by "<<b.directr<<"\n"
        <<"Released "<<b.yearRls<<"\n"
        <<"Run Time: "<<b.runTime<<"\n"
        <<"Production Cost: "<<b.prodCst<<"\n"
        <<"First Year Profit: "<<b.yr1prft<<endl;
}