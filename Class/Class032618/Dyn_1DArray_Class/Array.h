/* 
 * Author: Joel Avalos
 * Created on March 26th, 2018, 1:38 PM
 * Purpose:  Structure utilizing a Dynamic 1-D Array
 */

#ifndef ARRAY_H
#define ARRAY_H

class Array{
    private:
        int size;
        int *data;
    public:
        Array(int);
        ~Array(){delete []data;}
        int getData(int)const;
        int getSize()const{return size;}
};

#endif /* ARRAY_H */

