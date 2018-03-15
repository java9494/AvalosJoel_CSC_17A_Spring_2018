/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 13, 2018, 9:26 AM
 * Purpose: Create a modification to the United Cause case study program:
 * dynamically allocate an array of donations.
 */
 
 //System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void sort(float *[],int);
void dsplySt(float *[],int);
void dsplyOG(float [], int); 

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int numDon;//Number of user-inputted donations
    float *donate=nullptr;//Pointer to dynamically allocate
    
    //Initialize Variables 
    cout<<"Hello, enter in the number of donations."<<endl;
    cin>>numDon;
    donate=new float[numDon];
    
    //Process/Map inputs to outputs
    for (int count=0;count<numDon;count++){//Fill the dynamically allocated array
        cout<<"Please enter in the donation amount for Donation #"<<count+1<<endl;
        cin>>*(donate+count);
    }
    float *arrPtr[numDon];
    for (int count=0;count<numDon;count++){//Fill the array of pointers with address to dyn all array
        arrPtr[count]=&donate[count];
    }
    /*for (int count=0;count<numDon;count++){//Test
        cout<<*arrPtr[count]<<endl;
        cout<<*(donate+count)<<endl;
    }*/
    sort(arrPtr,numDon);
    cout<<"The donations in sorted ascending order are: "<<endl;
    dsplySt(arrPtr,numDon);
    cout<<"The donations in their original order are: "<<endl;
    dsplyOG(donate,numDon);
    
    //output data
    delete [] donate;  
    
    //Exit stage right!
    return 0;
}

void sort(float *arr[],int numDon){
    float *minElem;
    for (int scan=0;scan<(numDon-1);scan++){
        int min=scan;
        minElem=arr[scan];
        for (int index=scan+1;index<numDon;index++){
            if (*(arr[index]) < *minElem){
                minElem=arr[index];
                min=index;                
            }
        }
        arr[min]=arr[scan];
        arr[scan]=minElem;
    }
}

void dsplySt(float *arr[],int numDon){
    for (int count=0;count<numDon;count++){
        cout<<*arr[count]<<" ";
    }
    cout<<endl;
}

void dsplyOG(float arr[], int numDon){
    for (int count=0;count<numDon;count++){
        cout<<arr[count]<<" ";
    }
    cout<<endl;
}