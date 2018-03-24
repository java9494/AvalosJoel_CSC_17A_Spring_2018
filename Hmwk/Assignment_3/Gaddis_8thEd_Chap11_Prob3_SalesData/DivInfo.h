/* 
 * File:   DivInfo.h
 * Author: Joel
 * Purpose: Create a structure for each corporate division.
 * Created on March 24, 2018, 3:17 PM
 */

#ifndef DIVINFO_H
#define DIVINFO_H
using namespace std;

struct DivInfo {
    string divName;//Name of the division
    long int frstQtr,scndQtr,thrdQtr,frthQtr,//Each quarter of the year
             ttlSale;//Total annual sales
    float avgQtr;//Average for each quarter.
};


#endif /* DIVINFO_H */

