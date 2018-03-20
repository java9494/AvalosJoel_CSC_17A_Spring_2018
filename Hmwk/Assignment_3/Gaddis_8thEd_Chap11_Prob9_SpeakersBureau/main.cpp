/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on March 20, 2018, 10:56 AM
 * Purpose: Create a program that keeps track of a speakers' bureau.
 */
 
 //System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
#include "Spkr.h"
//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int numspkr;//number of speakers at conference
    int choice;//For menu
    
    //Initialize Variables
    cout<<"Speakers' Bureau Information Program"<<endl;
    cout<<"Hello, please enter in the number of speakers at the program."<<endl;
    cin>>numspkr;
    Speaker speaker[numspkr];//Creating array of structures
    do{
        cout<<setw(10)<<" "<<"Menu"<<endl;
        cout<<setw(10)<<" "<<"----"<<endl;
        cout<<"1. Enter in information for each speaker"<<endl;
        cout<<"2. Display the data of a specific speaker"<<endl;
        cout<<"3. Display the data of all speakers"<<endl;
        cout<<"4. Edit information about speaker"<<endl;
        cout<<"5. End program"<<endl;
        cin>>choice;

        switch (choice){
            case 1:
            {
                for (int count=0;count<numspkr;count++){
                    cout<<"Speaker #"<<count+1<<"'s Information"<<endl;
                    cin.ignore();
                    cout<<"Enter in name."<<endl;
                    getline(cin, speaker[count].name);
                    cout<<"Enter in their Telephone Number"<<endl;
                    getline(cin, speaker[count].teleNum);
                    cout<<"Enter in their speaking topic"<<endl;
                    getline(cin, speaker[count].topic);
                    cout<<"Enter in the fee required for attendance"<<endl;
                    cin>>speaker[count].feeRqrd;
                }
                break;
            }
            case 2:{
                int choice;
                if (choice>=0&&choice<=4){
                    cout<<"Enter in the speaker number you wish to view information for"<<endl;
                    cin>>choice;
                    cout<<"Speaker #"<<choice<<" information."<<endl;
                    cout<<speaker[choice].name<<endl;
                    cout<<speaker[choice].teleNum<<endl;
                    cout<<speaker[choice].topic<<endl;
                    cout<<"$"<<speaker[choice].feeRqrd<<endl;
                    break;
                }
                else
                    cout<<"Not a valid speaker."<<endl;
                break;
            }
            case 3:{
                for (int count=0;count<numspkr;count++){
                    cout<<"Speaker #"<<count<<" information."<<endl;
                    cout<<speaker[count].name<<endl;
                    cout<<speaker[count].teleNum<<endl;
                    cout<<speaker[count].topic<<endl;
                    cout<<fixed<<setprecision(2)<<showpoint;
                    cout<<"$"<<speaker[count].feeRqrd<<endl;
                }
                break;
            }
            case 4:{
                int spkrNum;
                int choice;
                cout<<"Which speaker do you wish to edit information for?"<<endl;
                cin>>spkrNum;
                cout<<"What information do you wish to change? Choose from:\n"
                    <<"1 for Name, 2 for Telephone Number, 3 for Speaking Topic, or 4 for Fee."<<endl;
                cin>>choice;
                switch (choice){
                    case 1:{
                        cin.ignore();
                        cout<<"Enter in new name."<<endl;
                        getline(cin, speaker[spkrNum].name); 
                        break;
                    }
                    case 2:{
                        cin.ignore();
                        cout<<"Enter in new telephone number."<<endl;
                        getline(cin, speaker[spkrNum].teleNum);
                        break;
                    }
                    case 3:{
                        cin.ignore();
                        cout<<"Enter in new speaking topic."<<endl;
                        getline(cin, speaker[spkrNum].topic);
                        break;
                    }
                    case 4:{
                        cin.ignore();
                        cout<<"Enter in new fee."<<endl;
                        cin>>speaker[spkrNum].feeRqrd;
                        break;
                    }
                    default: cout<<"Not a valid input."<<endl;
                }
                break;
            }
            case 5:{
                cout<<"Exiting program..."<<endl;
                break;
            }

            default: cout<<"Not a valid input. Exiting program..."<<endl;
        }
    }while(choice==1||choice==2||choice==3||choice==4);
    //Process/Map inputs to outputs
            
    //output data
            
    //Exit stage right!
    return 0;
}