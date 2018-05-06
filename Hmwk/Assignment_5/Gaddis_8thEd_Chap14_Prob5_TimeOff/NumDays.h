/* 
 * File:   NumDays.h
 * Author: Joel Avalos
 * Purpose: Class def
 * Created on May 6, 2018, 1:45 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays{
    private:
        float wrkhour;
        float wrkday;
    public:
        NumDays(float n);       
        float getHr() const
            {return wrkhour;}
        float getDay() const
            {return wrkday;}
        void setHr(float n)
            {wrkhour=n;}
        void setDay(float d)
            {wrkday=d/8.0f;}
        NumDays operator + (const NumDays &);
        NumDays operator - (const NumDays &);
        NumDays operator ++ (int);
        NumDays operator -- (int);
    
};

#endif /* NUMDAYS_H */

