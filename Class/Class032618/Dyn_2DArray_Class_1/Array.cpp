/* 
 * Author: Joel Avalos
 * Created on March 26th, 2018, 1:38 PM
 * Purpose:  Class specifications utilizing a Dynamic 2-D Array
 */

#include "Array.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Array::Array(int n,int m){
    rows=n<=1?2:n>1000?1000:n;
    cols=m<=1?2:m>1000?1000:m;
    *data=new int[rows];//Dynamically allocating memory
    for(int row=0;row<rows;row++){
        data[rows]=new int[cols];
    }
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            data[i][j]=rand()%90+10;//Limit to two digits.
        }        
    }
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
    for (int i=0;i<rows;i++){
        delete [] data[rows];
        }
    delete []data;
}
