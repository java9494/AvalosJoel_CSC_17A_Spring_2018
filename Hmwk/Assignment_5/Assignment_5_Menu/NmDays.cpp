/* 
 * File:   NmDays.cpp
 * Author: Joel Avalos
 * Purpose: Defining class functions
 * Created on May 6, 2018, 1:54 PM
 */

#include <iostream>
#include <cstdlib>

#include "NmDays.h"

using namespace std;

NmDays::NmDays(float n){
    wrkhour=n;
}
NmDays NmDays::operator + (const NmDays &right){
    NmDays temp(0.0f);
    temp.wrkhour=wrkhour+right.wrkhour;
    cout<<temp.wrkhour<<endl;
    return temp;
}

NmDays NmDays::operator - (const NmDays &right){
    NmDays temp(0.0f);
    temp.wrkhour=wrkhour-right.wrkhour;
    return temp;
}

NmDays NmDays::operator ++ (int){
    NmDays temp(0.0f);
    wrkhour++;
    cout<<wrkhour<<endl;
    temp.setHr(wrkhour);
    temp.setDay(wrkhour);
    return temp;
}

NmDays NmDays::operator -- (int){
    NmDays temp(0.0f);
    wrkhour--;
    temp.setHr(wrkhour);
    temp.setDay(wrkhour);
    return temp;
}