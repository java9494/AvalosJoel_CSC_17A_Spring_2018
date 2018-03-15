/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 13, 2018, 10:34 AM
 * Purpose: Create mean, median, mode functions for a given array.
 */
 
 //System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
float meanFct(float [],const int);
float medianF(float [],const int);
float modeFct(float [],const int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=5;
    float array[SIZE]={3,5,4,3,1};
    float mean,median,mode;
    
    //Initialize Variables
    mean=meanFct(array,SIZE);
    cout<<mean<<endl;
    median=medianF(array,SIZE);
    cout<<median<<endl;
    mode=modeFct(array,SIZE);
    if (mode==1)
        cout<<"There is no mode for this set of numbers."<<endl;
    else
        cout<<mode<<endl;
    
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
    return 0;
}

float meanFct(float array[],const int size){
    float mean=0;
    for (int count=0;count<size;count++){
        mean+=array[count];
    }
    mean/=static_cast<float>(size);
    return mean;
}

float medianF(float array[],const int size){
    bool swap;
    float median;
    do{
        swap=false;
        for (int count=0;count<(size-1);count++){
            if (array[count]>array[count+1]){
                float temp;
                temp=array[count];
                array[count]=array[count+1];
                array[count+1]=temp;  
                swap=true;
            }
        }
    }while(swap);
    if (size%2!=0){//If number of values is odd, middle number is median
        median=array[size/2];
    }
    else {
        median=(array[size/2]+array[size/2-1])*0.5;
    }
    return median;
}

float modeFct(float array[],const int size){
    int occur[size];
    for (int count=0;count<size;count++)//Setting default number of occ to 0
        occur[count]=0;
    for (int index=0;index<size;index++){//Beginning with first value of array,
        float value=array[index];//and continuing till last value in array
        for (int count=0;count<size;count++){//Search entire array for multiple
            if (array[count]==value)//occurences of the same value
                occur[count]++;
        }
    }
    /*for (int count=0;count<size;count++){//Display occurences
        cout<<occur[count]<<endl;
    }*/
    int maxFreq;
    bool max;
    maxFreq=occur[0];
    do{
        max=false;
        //cout<<"Hello from do while!"<<endl;
        for (int count=0;count<size;count++){
            if (occur[count+1]>maxFreq){
                maxFreq=occur[count+1];
                //cout<<maxFreq<<endl;
                max=true;
            }
                //cout<<"Hello!from for loop"<<endl;
        }
    }while(max);
    if (maxFreq==1){
        float mode=1;
        return mode;
    }
    float mode=array[maxFreq];
    return mode;
}