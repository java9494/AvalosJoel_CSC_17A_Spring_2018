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
        DayYear(string,int);//Newly added constructor
        void setDate(int d)
            {date=d;}
        void setDate(DayYear,int);
        void print(DayYear,int);
        string getMnth(int m) const
            {return month[m];}
        int getDate() const
            {return date;}
        DayYear operator ++ (int);
        DayYear operator -- (int);
        void simplfy();
};
        
        


#endif /* DAYYEAR_H */

