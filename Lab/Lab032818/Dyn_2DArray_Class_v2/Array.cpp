/* 
 * Author: Joel Avalos
 * Created on March 26th, 2018, 1:38 PM
 * Purpose:  Class specifications utilizing a Dynamic 2-D Array
 */

#include "Array.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Array::Array(int n,int m){
    rows=n<=1?2:n>1000?1000:n;
    cols=m<=1?2:m>1000?1000:m;
    //cout<<"Hi before allocating<"<<endl;
    *data=new int[rows];//Dynamically allocating memory
    //cout<<"Hi< after allocating"<<endl;
    for(int count=0;count<rows;count++){
        data[count]=new int[cols];
    }
    //cout<<"Hi< after allocating more"<<endl;
    for (int i=0;i<rows;i++){
        //cout<<"Hi from first loop"<<endl;
        for (int j=0;j<cols;j++){
            //cout<<"HI from second loop"<<endl;
            data[i][j]=rand()%90+10;//Limit to two digits.
            //cout<<data[i][j]<<endl;
        }        
    }
    //cout<<"Hi after generating array with random numbers"<<endl;
};

int Array::getData(int indx,int indx2)const{
    if (indx>=0&&indx<rows){
        if (indx2>=0&&indx2<cols)
            return data[indx][indx2];
    }
    else
        return data[0][0];
}

Array::~Array(){
    //cout<<"Hello from destructor function!"<<endl;
    for (int i=0;i<rows;i++){
        //cout<<"Hello from d function loop!"<<endl;
        delete [] data[i];
        }
    //cout<<"Hello after d loop!"<<endl;
    data=nullptr;
    //cout<<"Hello at end of destructor function!"<<endl;
}
