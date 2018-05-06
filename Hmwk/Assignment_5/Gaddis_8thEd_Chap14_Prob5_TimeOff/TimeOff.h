/* 
 * File:   TimeOff.h
 * Author: Joel Avalos
 * Purpose: Class definition
 * Created on May 6, 2018, 2:41 PM
 */

#include "NumDays.h"
#ifndef TIMEOFF_H
#define TIMEOFF_H

using namespace std;

class TimeOff{
    private:
        float mxSick;
        float sickTkn;
        float mxVac;
        float vacTkn;
        float maxUnpd;
        float unpdTkn;
        string empName;
        string idnum;
    public:
        TimeOff(NumDays emp);
        void setMxS(NumDays emp)
            {mxSick=emp.getDay()/31.0f+8;}
        void setStk(float n)
            {sickTkn=n;}
        void setMxV(NumDays emp)
            {mxVac=emp.getDay()/31.0f+12;}
        void setvcTk(float n)
            {vacTkn=n;}
        void setMxU(NumDays emp)
            {maxUnpd=emp.getDay();}
        void setuTkn(float n)
            {unpdTkn=n;}
        void setName(string n)
            {empName=n;}
        void setID(string n)
            {idnum=n;}
        float getMxS() const
            {return mxSick;}
        float getStk() const
            {return sickTkn;}
        float getMxV() const
            {return mxVac;}
        float getvcTk() const
            {return vacTkn;}
        float getMxU() const
            {return maxUnpd;}
        float getuTkn() const
            {return unpdTkn;}
        string getName() const
            {return empName;}
        string getMxS() const
            {return idnum;}
        
};


#endif /* TIMEOFF_H */

