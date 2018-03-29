/* 
 * Author: Joel Avalos
 * Created on March 26th, 2018, 1:38 PM
 * Purpose:  Structure utilizing a Dynamic 1-D Array
 */

#ifndef ARRAY_H
#define ARRAY_H

class Array{
    private:
        int rows;
        int cols;
        int **data;
    public:
        Array(int,int);
        ~Array();
        int getData(int,int)const;
        int getRows()const{return rows;}
        int getCols()const{return cols;}
};

#endif /* ARRAY_H */


