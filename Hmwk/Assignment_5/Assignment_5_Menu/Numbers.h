/* 
 * File:   Numbers.h
 * Author: Joel Avalos
 * Purpose: Defining Numbers class
 * Created on May 6, 2018, 9:22 AM
 */

#ifndef NUMBERS_H
#define NUMBERS_H
using namespace std;

class Numbers {
    private: 
        int number;
        static string ones[19];
        static string tens[8];
        static string hundred;
        static string thousnd;
    public:
        void print(Numbers,int);
        void setNum(int n)
            {number=n;}
        string getOnes(int n) const
            {return ones[n];}
        string getTen(int n) const
            {return tens[n];}
        string getHund() const
            {return hundred;}
        string getThou() const
            {return thousnd;}
};

#endif /* NUMBERS_H */

