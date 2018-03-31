/* 
 * File:   Date.h
 * Author: Joel Avalos
 * Created on March 31, 2018, 8:36 AM
 * Purpose: Create a Date class.
 */

#ifndef DATE_H
#define DATE_H

class Date {
    private:
        int month,
            day,
            year;
    public:
        Date();//Constructor
        void setMnth(int);//Set ers
        void setDay(int);
        void setYear(int);
        int getMnth() const {return month;}//Get ers
        int getDay() const {return day;}
        int getYear() const {return year;}
        void prnt1(int,int,int);//Print date in  MM/DD/YYYY format
        void prnt2(int,int,int);//Print date in  Month Date, Year format
        void prnt3(int,int,int);//Print date in Day Month Year format
        
};


#endif /* DATE_H */

