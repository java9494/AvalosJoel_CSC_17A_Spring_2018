/* 
 * File:   num.cpp
 * Author: Joel Avalos
 * Purpose: num class implementation file
 * Created on May 6, 2018, 9:37 AM
 */

#include <cstdlib>
#include <iostream>
#include "Numbers.h"

using namespace std;


string Numbers::hundred="hundred";
string Numbers::thousnd="thousand";
string Numbers::ones[19]={"one","two","three","four","five","six","seven",
                                "eight","nine","ten","eleven","twelve","thirteen",
                                "fourteen","fifteen","sixteen","seventeen",
                                "eighteen","nineteen"};
string Numbers::tens[8]={"twenty","thirty","forty","fifty","sixty",
                               "seventy","eighty","ninety"};

void Numbers::print(Numbers num, int number){
    int orgNum=number;
     int n1000s=(number-number%1000)/1000;
        number%=1000;
        int n100s=(number-number%100)/100;
        number%=100;
        int n10s=(number-number%10)/10;
        number%=10;
        int n1s=number;
        int numchk=orgNum%1000%100;

        //Process numbers to words
        if (number==0)
            cout<<"zero"<<endl;
        else {
            switch (n1000s){
                case 9: cout<<num.getOnes(n1000s-1)<<" "<<num.getThou()<<" ";break;
                case 8: cout<<num.getOnes(n1000s-1)<<" "<<num.getThou()<<" ";break;
                case 7: cout<<num.getOnes(n1000s-1)<<" "<<num.getThou()<<" ";break;
                case 6: cout<<num.getOnes(n1000s-1)<<" "<<num.getThou()<<" ";break;
                case 5: cout<<num.getOnes(n1000s-1)<<" "<<num.getThou()<<" ";break;
                case 4: cout<<num.getOnes(n1000s-1)<<" "<<num.getThou()<<" ";break;             
                case 3: cout<<num.getOnes(n1000s-1)<<" "<<num.getThou()<<" ";break;
                case 2: cout<<num.getOnes(n1000s-1)<<" "<<num.getThou()<<" ";break;
                case 1: cout<<num.getOnes(n1000s-1)<<" "<<num.getThou()<<" ";break;
                case 0:break;
            }

            switch (n100s){
                case 9: cout<<num.getOnes(n100s-1)<<" "<<num.getHund()<<" ";break;
                case 8: cout<<num.getOnes(n100s-1)<<" "<<num.getHund()<<" ";break;
                case 7: cout<<num.getOnes(n100s-1)<<" "<<num.getHund()<<" ";break;
                case 6: cout<<num.getOnes(n100s-1)<<" "<<num.getHund()<<" ";break;
                case 5: cout<<num.getOnes(n100s-1)<<" "<<num.getHund()<<" ";break;
                case 4: cout<<num.getOnes(n100s-1)<<" "<<num.getHund()<<" ";break;
                case 3: cout<<num.getOnes(n100s-1)<<" "<<num.getHund()<<" ";break;
                case 2: cout<<num.getOnes(n100s-1)<<" "<<num.getHund()<<" ";break;
                case 1: cout<<num.getOnes(n100s-1)<<" "<<num.getHund()<<" ";break;
                case 0: break;
            }
            //Elevens through Nineteen
            if (orgNum>=11&&orgNum<=19){
                switch (orgNum){
                    case 11: cout<<num.getOnes(orgNum-1);break;
                    case 12: cout<<num.getOnes(orgNum-1);break;
                    case 13: cout<<num.getOnes(orgNum-1);break;
                    case 14: cout<<num.getOnes(orgNum-1);break;
                    case 15: cout<<num.getOnes(orgNum-1);break;
                    case 16: cout<<num.getOnes(orgNum-1);break;
                    case 17: cout<<num.getOnes(orgNum-1);break;
                    case 18: cout<<num.getOnes(orgNum-1);break;
                    case 19: cout<<num.getOnes(orgNum-1);break;
                }
            }
            else if (orgNum>19&&numchk<20){
                switch (numchk){
                    case 11: cout<<num.getOnes(orgNum-1);break;
                    case 12: cout<<num.getOnes(orgNum-1);break;
                    case 13: cout<<num.getOnes(orgNum-1);break;
                    case 14: cout<<num.getOnes(orgNum-1);break;
                    case 15: cout<<num.getOnes(orgNum-1);break;
                    case 16: cout<<num.getOnes(orgNum-1);break;
                    case 17: cout<<num.getOnes(orgNum-1);break;
                    case 18: cout<<num.getOnes(orgNum-1);break;
                    case 19: cout<<num.getOnes(orgNum-1);break;  
                }
            }

            else {
                switch (n10s){
                    case 9: cout<<num.getTen(n10s-2)<<" ";break;
                    case 8: cout<<num.getTen(n10s-2)<<" ";break;
                    case 7: cout<<num.getTen(n10s-2)<<" ";break;
                    case 6: cout<<num.getTen(n10s-2)<<" ";break;
                    case 5: cout<<num.getTen(n10s-2)<<" ";break;
                    case 4: cout<<num.getTen(n10s-2)<<" ";break;
                    case 3: cout<<num.getTen(n10s-2)<<" ";break;
                    case 2: cout<<num.getTen(n10s-2)<<" ";break;
                    case 1: cout<<num.getOnes(9);break;
                    case 0: break;

                }      

                switch (n1s){
                    case 9: cout<<num.getOnes(n1s-1);break;
                    case 8: cout<<num.getOnes(n1s-1);break;
                    case 7: cout<<num.getOnes(n1s-1);break;
                    case 6: cout<<num.getOnes(n1s-1);break;
                    case 5: cout<<num.getOnes(n1s-1);break;
                    case 4: cout<<num.getOnes(n1s-1);break;
                    case 3: cout<<num.getOnes(n1s-1);break;
                    case 2: cout<<num.getOnes(n1s-1);break;
                    case 1: cout<<num.getOnes(n1s-1);break;
                }
            }
    }
        cout<<endl;
}

