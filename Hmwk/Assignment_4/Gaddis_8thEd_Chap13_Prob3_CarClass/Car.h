/* 
 * File:   Car.h
 * Author: Joel Avalos
 * Purpose: Create a Car Class
 * Created on April 4, 2018, 4:17 PM
 */

#ifndef CAR_H
#define CAR_H
using namespace std;

class Car{
    private:
        int yrModel;
        string make;
        int speed;
    public:
        Car(int y,string m){
            make=m;
            yrModel=y;
            speed=0;
        }
        int getMdel() const {return yrModel;}
        string getMake() const {return make;}
        int getSpd() const {return speed;}
        int acc() {speed+=5;}
        int dec() {speed-=5;}
};

#endif /* CAR_H */

