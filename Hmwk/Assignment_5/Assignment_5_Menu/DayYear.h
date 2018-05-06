/* 
 * File:   DayYear.h
 * Author: Joel Avalos
 * Purpose: Defining class
 * Created on May 6, 2018, 11:07 AM
 */

#ifndef DAYYEAR_H
#define DAYYEAR_H
using namespace std;

class DayYear{
    private:
        int date;
        static string month[12];
    public:
        void setDate(DayYear,int);
        void print(DayYear,int);
        string getMnth(int m) const
            {return month[m];}
};
        
        


#endif /* DAYYEAR_H */

