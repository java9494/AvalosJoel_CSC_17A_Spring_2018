/* 
 * File:   GmeGrid.h
 * Author: Joel Avalos
 * Purpose: Create a structure for grid variables.
 * Created on April 15, 2018, 6:55 PM
 */

#ifndef GMEGRID_H
#define GMEGRID_H

class GmeGrid {
    private:
        int spots;//Grid
        bool isitBug;//Bug or not
        char clrDsp;//What a space will display after being cleared.
        int nbrBugs;//The number of bugs neighboring a space on the grid
    public:
        int getSpot()
        {return spots;}
        void setSpot(int x)
        {spots=x;}
        bool getTru()
        {return isitBug;}
        void setTru(bool y)
        {isitBug=y;}
        void setDsp(char z)
        {clrDsp=z;}
        char getDsp()
        {return clrDsp;}
        int getNbr()
        {return nbrBugs;}
        void setNbr(int a)
        {nbrBugs=a;}
};


#endif /* GMEGRID_H */

