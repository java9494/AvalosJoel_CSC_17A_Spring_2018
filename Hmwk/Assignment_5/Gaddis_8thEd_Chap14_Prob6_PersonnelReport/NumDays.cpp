/* 
 * File:   NumDays.cpp
 * Author: Joel Avalos
 * Purpose: Defining class functions
 * Created on May 6, 2018, 1:54 PM
 */

#include <iostream>
#include <cstdlib>

#include "NumDays.h"

using namespace std;

NumDays::NumDays(float n){
    wrkhour=n;
}
NumDays NumDays::operator + (const NumDays &right){
    NumDays temp(0.0f);
    temp.wrkhour=wrkhour+right.wrkhour;
    cout<<temp.wrkhour<<endl;
    return temp;
}

NumDays NumDays::operator - (const NumDays &right){
    NumDays temp(0.0f);
    temp.wrkhour=wrkhour-right.wrkhour;
    return temp;
}

NumDays NumDays::operator ++ (int){
    NumDays temp(0.0f);
    wrkhour++;
    cout<<wrkhour<<endl;
    temp.setHr(wrkhour);
    temp.setDay(wrkhour);
    return temp;
}

NumDays NumDays::operator -- (int){
    NumDays temp(0.0f);
    wrkhour--;
    temp.setHr(wrkhour);
    temp.setDay(wrkhour);
    return temp;
}