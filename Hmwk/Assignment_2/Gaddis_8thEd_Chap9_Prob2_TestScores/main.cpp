/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 13, 2018, 8:01 AM
 * Purpose: Create a test score program.
 */
 
 //System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void sort(float [],int);//Sorting test scores in ascending order
float avg (float [],int);//Calculates the average score
void display (float [],float,int);//Displays information in a fancy way

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float *tests=nullptr;
    float average;
    int numTest;//Number of test scores
    
    
    //Initialize Variables 
    cout<<"Hello, please enter the number of test scores you wish to input.\n";
    cin>>numTest;
    tests=new float[numTest];
    cout<<"Enter in each test score"<<endl;
    for (int count=0;count<numTest;count++){
        cout<<"Enter in Test Score #"<<count+1<<endl;
        cin>>*(tests+count);
    }
 
    //Process/Map inputs to outputs
    sort(tests,numTest);
    average=avg(tests,numTest);
    display(tests,average,numTest);
            
    //output data
    delete [] tests;//No memory leaks here!
            
    //Exit stage right!
    return 0;
}

void sort(float test[], int numTest){//Sorting test scores in ascending order
    bool swap;
    do {
        swap=false;
        for (int index=0;index<(numTest-1);index++)
            if (*(test+index) > *(test+index+1)){
                float temp;
                temp=*(test+index);
                *(test+index)=*(test+index+1);
                *(test+index+1)=temp;
                swap=true;
            }
    }while(swap);
}

float avg (float test[], int numTest){//Calculates the average score
    float average=0;
    for (int count=0;count<numTest;count++){
        average+=*(test+count);
    }
    average=average/numTest;
    return average;
}

void display (float test[],float average,int numTest){//Displays information in a fancy way
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Test Scores"<<endl;
    cout<<"----------"<<endl;
    for (int count=0;count<numTest;count++){
        cout<<*(test+count)<<" ";
        if (numTest>10&&count%10==0)
            cout<<endl;
        if (count==(numTest-1))
            cout<<endl;
    }
    cout<<" "<<endl;
    cout<<"Average Test Score"<<endl;
    cout<<"-------------------"<<endl;
    cout<<average<<endl;
        
}