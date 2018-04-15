/* 
 * File:   Circle.h
 * Author: Joel Avalos
 * Purpose: Create a circle class
 * Created on April 4, 2018, 8:42 PM
 */

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
    private:
        float radius;
        float pi=3.14159;
    public:
        Circle() {radius=0.0f;}
        Circle (float r) {
            radius=r;
        }
        void setRad(float r) {radius=r;}
        float getRad() const {return radius;}
        float getArea() const {return pi*radius*radius;}
        float getDiam() const {return radius*2;}
        float getCir() const {return 2*pi*radius;}
         
};


#endif /* CIRCLE_H */

