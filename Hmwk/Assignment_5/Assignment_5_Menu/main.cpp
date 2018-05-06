/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on May 6, 2018, 3:24 PM
 * Purpose: Create a menu program for Assignment 5.
 */
 
 //System Libraries
#include <iostream>

#include "Numbers.h"
#include "DayYear.h"
#include "DyYear.h"
#include "NumDays.h"
#include "NmDays.h"
#include "TimeOff.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void Menu();
int getN();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();

//Execution Begins Here
int main(int argc, char** argv) {   
    //Declare Variables
    int inN;
        do{
             Menu();
             inN=getN();
             switch(inN){
              case 1:    problem1();break;
              case 2:    problem2();break;
              case 3:    problem3();break;
              case 4:    problem4();break;
              case 5:    problem5();break;
                 default: cout<<"You have chosen to exit."<<endl;break;
             }
        }while(inN<6&&inN>0);
    //Initialize Variables
    
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
    return 0;
}

void Menu(){
    cout<<"Assignment 5 Menu"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Choose from the following problems:"<<endl;
    cout<<"1 - Problem 1"<<endl;
    cout<<"2 - Problem 2"<<endl;
    cout<<"3 - Problem 3"<<endl;
    cout<<"4 - Problem 4"<<endl;
    cout<<"5 - Problem 5"<<endl;
    cout<<"Enter in any other number to exit."<<endl;
            
}

int getN(){
    int choice;
    cin>>choice;
    return choice;
}

void problem1(){
    Numbers num;
    int n;
    cout<<"Hello, enter in a number you wish to convert to English."<<endl;
    cin>>n;
    num.setNum(n);
    num.print(num,n);
}

void problem2(){
    DayYear day;
    int numb;
    cout<<"Hello! Please enter in the day of the year that you wish to translate into Month Day format."<<endl;
    cin>>numb;
    day.setDate(day,numb);
    day.print(day,numb);
}

void problem3(){
    string month;
    int date;
    cout<<"Hello! Enter in a month, then a number between 1-31, to output the day of the year that is."<<endl;
    cin>>month;
    cin>>date;
    DyYear day(month,date);
    cout<<"Day "<<day.getDate()<<"."<<endl;
}

void problem4(){
    //Declare Variables
    float numHrs,numHrs2;
    cout<<"Hello, enter in the number of hours worked. I will convert to a number of days."<<endl;
    cin>>numHrs;
    NumDays num(numHrs);
    num.setHr(numHrs);
    num.setDay(numHrs);
    
    //Initialize Variables
    cout<<num.getDay()<<" days."<<endl;
    
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
}

void problem5(){
    //Declare Variables
    float numHrs;
    cout<<"Hello, enter in the number of hours worked. I will convert to a number of days."<<endl;
    cin>>numHrs;
    NumDays num(numHrs);
    num.setHr(numHrs);
    num.setDay(numHrs);
    TimeOff emp;
    emp.setMxS(num);
    emp.setMxV(num);
    
    //Initialize Variables
    cout<<num.getDay()<<" days."<<endl;
    cout<<emp.getMxS()<<" hours of sick leave."<<endl;
    cout<<emp.getMxV()<<" hours of paid vacation leave."<<endl;
    
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
}