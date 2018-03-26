/* 
 * Author: Joel Avalos
 * Created on March 26th, 2018, 1:38 PM
 * Purpose:  Class specifications utilizing a Dynamic 1-D Array
 */

#include "Array.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Array::Array(int n){
    size=n<=1?2:n>1000?1000:n;
    data=new int[size];
    for (int i=0;i<size;i++){
        data[i]=rand()%90+10;//Limit to two digits.
        
    }
};

int Array::getData(int indx)const{
    if (indx>=0&&indx<size)
        return data[indx];
    else
        return data[0];
}


