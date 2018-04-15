/* 
 * File:   PerInfo.h
 * Author: Joel
 * Purpose: Create a personal information class
 * Created on April 4, 2018, 8:01 PM
 */

#ifndef PERINFO_H
#define PERINFO_H
using namespace std;

class PerInfo {
    private: string name;
             string age;
             string address;
             string phone;
    public:
        PerInfo(string n,string a,string add,string f){
            name=n;
            age=a;
            address=add;
            phone=f;
        }
        void setName(string n) {name=n;}
        void setage(string a) {age=a;}
        void setAdd(string a) {address=a;}
        void setFone(string f) {phone=f;}
        string getName() const {return name;}
        string getAge() const {return age;}
        string getAdd() const {return address;}
        string getFone() const {return phone;}
};

#endif /* PERINFO_H */

