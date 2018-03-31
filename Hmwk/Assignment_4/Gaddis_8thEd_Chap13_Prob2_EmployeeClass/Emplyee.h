/* 
 * File:   Emplyee.h
 * Author: Joel Avalos
 * Purpose: Create an Employee class
 * Created on March 31, 2018, 9:50 AM
 */

using namespace std;

#ifndef EMPLYEE_H
#define EMPLYEE_H

class Emplyee {
    private:
        string name;//Employee's name
        int idNum;//Employee's ID number
        string dprtmnt;//Employee's department
        string pos;//Position employee holds
    public:
        Emplyee(string n,int id,string d,string p){//Constructor #1
        name=n;
        idNum=id;
        dprtmnt=d;
        pos=p;
        }
        Emplyee(string n,int id){//Constructor #2
            name=n;
            idNum=id;
            dprtmnt="";
            pos="";
        }
        Emplyee(){//Default constructor
            name="";
            idNum=0;
            dprtmnt="";
            pos="";
        }
        void setName(string n) {name=n;}
        void setID(int id) {idNum=id;}
        void setDpt(string d) {dprtmnt=d;}
        void setPos(string p) {pos=p;}
        string getName() const {return name;}
        int getID() const {return idNum;}
        string getDpt() const {return dprtmnt;}
        string getPos() const {return pos;}        
};


#endif /* EMPLYEE_H */

EMPLYEE_H