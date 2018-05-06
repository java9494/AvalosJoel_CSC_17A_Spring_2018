/* 
 * File:   DayYear.h
 * Author: Joel Avalos
 * Purpose: Defining class
 * Created on May 6, 2018, 11:07 AM
 */

#ifndef DYYEAR_H
#define DYYEAR_H
using namespace std;

class DyYear{
    private:
        int date;
        static string month[12];
    public:
        DyYear(string,int);//Newly added constructor
        void setDate(int d)
            {date=d;}
        void setDate(DyYear,int);
        void print(DyYear,int);
        string getMnth(int m) const
            {return month[m];}
        int getDate() const
            {return date;}
        DyYear operator ++ (int);
        DyYear operator -- (int);
        void simplfy();
};
        
        


#endif /* DYYEAR_H */

