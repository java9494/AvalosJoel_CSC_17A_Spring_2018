/* 
 * File:   GmeGrid.h
 * Author: Joel Avalos
 * Purpose: Create a structure for grid variables.
 * Created on April 15, 2018, 6:55 PM
 */

#ifndef GMEGRID_H
#define GMEGRID_H

struct GmeGrid {
    int spots;//Grid
    bool isitBug;//Bug or not
    char clrDsp;//What a space will display after being cleared.
    int nbrBugs;//The number of bugs neighboring a space on the grid
};


#endif /* GMEGRID_H */

