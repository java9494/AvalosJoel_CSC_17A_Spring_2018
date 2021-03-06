/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 26th, 2018, 1:35 PM
 * Purpose:  Class utilizing a Dynamic 2-D Array
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //srand, rand
#include <ctime>     //Time
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants - Math, Science, Conversions, 2D Array Sizes

//Function Prototypes
void prntAry(const Array &);

//Executions Begin Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and allocate memory for the array
    //cout<<"Hi<"<<endl;
    int rows=10;
    int cols=10;
    //cout<<"Hi<"<<endl;
    Array array(rows,cols);
    
    //Print the random 2-Digit array
    //cout<<"Hi before printing array"<<endl;
    prntAry(array);
    //cout<<"Hi after printing array!"<<endl;
    //Exit stage right!
    return 0;
}

void prntAry(const Array &a){
    cout<<endl;
    for(int i=0;i<a.getRows();i++){
        for (int j=0;j<a.getCols();j++){
            cout<<a.getData(i,j)<<" ";
        }
        cout<<endl;
    }
}