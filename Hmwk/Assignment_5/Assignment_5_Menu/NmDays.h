/* 
 * File:   NmDays.h
 * Author: Joel Avalos
 * Purpose: Class def
 * Created on May 6, 2018, 1:45 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NmDays{
    private:
        float wrkhour;
        float wrkday;
        friend class TimeOff;
    public:
        NmDays(float n);       
        float getHr() const
            {return wrkhour;}
        float getDay() const
            {return wrkday;}
        void setHr(float n)
            {wrkhour=n;}
        void setDay(float d)
            {wrkday=d/8.0f;}
        NmDays operator + (const NmDays &);
        NmDays operator - (const NmDays &);
        NmDays operator ++ (int);
        NmDays operator -- (int);
    
};

#endif /* NUMDAYS_H */

