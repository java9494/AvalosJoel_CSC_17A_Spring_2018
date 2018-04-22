/* 
 * File:   GStates.h
 * Author: Joel Avalos
 * Purpose: To create a structure that will hold game state variables and functions.
 * Created on April 14, 2018, 6:21 PM
 */

#ifndef GSTATES_H
#define GSTATES_H

struct GStates {
        bool gameWin=false;//Win condition of the game
        bool gameLss=false;//Losing condition  
        bool scores;//Flag for score-keeping
};


#endif /* GSTATES_H */

