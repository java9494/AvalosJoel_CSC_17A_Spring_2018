/* 
 * File:   RetItem.h
 * Author: Joel Avalos
 * Purpose: Create a retail item class.
 * Created on April 4, 2018, 8:22 PM
 */

#ifndef RETITEM_H
#define RETITEM_H
using namespace std;

class RetItem {
    private:
        string desc;//Description of the item
        int onHand;//Number of units currently in inventory
        float price;//Price of the item
    public:
        RetItem(string d,int o,float p){
            desc=d;
            onHand=o;
            price=p;
        }
        string setDesc(string d) {desc=d;}
        int setHand(int o) {onHand=o;}
        float setPrce(float p) {price=p;}
        string getDesc() const {return desc;}
        int getHand() const {return onHand;}
        float getPrce() const {return price;}
};


#endif /* RETITEM_H */

