/* 
 * File:   MovData.h
 * Author: Joel
 * Created on March 23, 2018, 1:09 PM
 * Purpose: Create a movie data structure
 */

#ifndef MOVDATA_H
#define MOVDATA_H
using namespace std;

struct MovData {//Structure to hold movie info
    string title,//Title of movie
           directr,//Director of movie
           yearRls,//Year movie was released
           runTime,//Running time of movie
           prodCst,//Production cost of the movie
           yr1prft;//Profit earned in the first year of release
    
};

#endif /* MOVDATA_H */

