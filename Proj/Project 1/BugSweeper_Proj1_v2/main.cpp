/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on April 10, 2018, 6:25 PM
 * Purpose: Create a full version of MineSweeper, using concepts from 
 * Chapter 9-12 of Gaddis.
 * v1: Created structures to condense game variables into.
 * v2: Created a difficulty modifier using 2-D pointers.
 */
 
//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector>

#include "GStates.h"
#include "GmeGrid.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const int COLS=10;//Constant for the number of columns in the 2-D Array
const int COLS2=15;//Constant for the number of columns in pro setting Grid

//Function Prototypes
void random(GmeGrid [][COLS],int);//Function to randomize each spot on grid.
void bugTest(GmeGrid [][COLS],int);//Function to test whether a spot is a bug.
int nbrBug(GmeGrid [][COLS],int);//Function to calculate number of Bugs on grid
                            //A well as to activate Bug spaces.
void nbrBugs(GmeGrid [][COLS],int);//Function to calculate neighboring bugs around each space
void start (string);//Function to run the game's Start Menu
void game(GmeGrid [][COLS],
        int,char,int,int,bool,bool,int &,int &,string,bool [],vector<bool>,int);//Function to run the game
void cleared(GmeGrid [][COLS],
        int,char,int,int,bool &,bool &,int &,int &,string,bool [],vector<bool>,int);//Function to clear each user-inputted space
void display(GmeGrid [][COLS],int);//Function for displaying the grid.
int dffclty();
void rules(GmeGrid [][COLS],int);//Function for displaying the Rules of the game.
bool scoreKp();//Function for keeping records
void savRecs(int &,int,string,bool [],vector<bool>,int);//Function for saving records
void exit();//Function to exit the program

//Execution Begins Here
int main(int argc, char** argv) {   
    //Seeding the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaring Game, Grid, and Array Variables
    string title;//Game title
    const int ROWS=6;//Rows in the grid.
    GmeGrid grid[ROWS][COLS];
    int nBugs;//The total number of bugs in the game
    const int MXGAMES=100;//Max number of games to record keep is 100
    bool gamesW[MXGAMES];//Array to hold number of games won
    vector<bool> gamesL(MXGAMES,false);//Vector to hold number of games lost
    int gameNum=0;//Count of how many games user has played
    int totGame;//Total games played
    int dff=2;//Game difficulty variable set to default setting
    int **proGrid;//Pointer used to allocate memory for a bigger grid
 
    //Declaring User-inputted Variables
    char row;//User-inputted choice for the row that the space they want to clear is in
    int spot;//User-inputted choice for the space they want to clear
    int in;//Menu choice
    string name;//Name for record keeping
    
    do{//Start the Game loop
    
    //Initializing Variables
    GStates gmeStrt;
    title="BugSweeper";//Title of Game!
    ifstream inFile;
    inFile.open("totGame.txt");
    inFile>>totGame;    
       
    //Start Menu
    start(title);//Call start menu function
    cin>>in;//Ask user for input
    switch (in){//This is the switch case for the menu
        case 1:
            if (dff==2){
                //Initializing random numbers and display values
                random(grid,ROWS);//Call random function to randomize the grid
                for (int x=0;x<ROWS;x++){//Loop to set each space's initial Bug value to false
                    for (int y=0;y<COLS;y++){
                        grid[x][y].isitBug=false;
                    }
                }
                for (int x=0;x<ROWS;x++){//Loop to set each space's initial display to an X
                    for (int y=0;y<COLS;y++){
                        grid[x][y].clrDsp='X';
                    }
                }
            }
            for (int x=0;x<MXGAMES;x++)//Loop to set game wins to false
                gamesW[x]=false;
            /*if (dff=3){
                proGrid = new int[][COLS2];
            }*/
    
            //Initializing the Bugs
            bugTest(grid,ROWS);//Call the bugTest function to arm bugs
            nBugs=nbrBug(grid,ROWS);//Call nBug function to add up the total number of bugs in the game.
                /*for (int x=0;x<ROWS;x++){//Loop to display the grid with bug locations for debugging purposes
                for (int y=0;y<COLS;y++){
                    cout<<isitBug[x][y]<<" ";
                    if (y==9)
                        cout<<endl;
                }
            }*/
                game(grid,ROWS,row,spot,nBugs,gmeStrt.gameWin,gmeStrt.gameLss,
                totGame,gameNum,name,gamesW,gamesL,MXGAMES);//Run game
            break;
        case 2: dff=dffclty();break;//Difficulty modifier
        case 3: rules(grid,ROWS);break;//Display rules
        case 4: gmeStrt.scores=scoreKp();//Option to keep records
        if (gmeStrt.scores){
        cout<<"Please enter a name."<<endl;
        cin>>name;
        }
        break;
        default: exit();break;//Or, exit program
    }
    }while (in==1||in==2||in==3||in==4);//Display menu while user inputs menu choices 1 or 2
 
    //Exit stage right!
    return 0;
}
    
void random(GmeGrid grid[][COLS],int rows){//Randomizing the grid.
    for (int x=0;x<rows;x++){
        for (int y=0;y<COLS;y++){
            grid[x][y].spots=rand();//Going through every element in array to randomize
        }
    }
}

void bugTest(GmeGrid grid[][COLS],int rows){//Testing each space for bugs.
    for (int x=0;x<rows;x++){
        for (int y=0;y<COLS;y++){
            if (grid[x][y].spots%3==0){//Bug criteria: if the random number
                                 //Assigned to a space is cleanly divisible by 3
                                 //(no remainder), then that space is a bug
                grid[x][y].isitBug=true;//Set bug test to true       
            }
        }
    }
}

int nbrBug(GmeGrid grid[][COLS],int rows){//Adding up the number of bugs on the grid
    int nbugs=0;
    for (int x=0;x<rows;x++){
        for (int y=0;y<COLS;y++){
            if (grid[x][y].isitBug==true){//Checking bool value for bug
                nbugs++;//Counting number of bugs for the win condition
            }
        }
    }
    return nbugs;
}

void nbrBugs(GmeGrid grid[][COLS],int rows){//Testing neighboring
                                                            //spaces on grid for bugs
    for (int x=0;x<rows;x++){//Testing neighboring spaces of column 0 spaces for bugs
        int nbrBug=0;
        if (grid[0+x][1].isitBug==true)
            nbrBug++;
        if ((grid[1+x][0].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][1].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[x-1][0].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][1].isitBug==true)&&(x!=0))
            nbrBug++;
        grid[x][0].isitBug=nbrBug;
    }
    for (int x=0;x<rows;x++){//Testing neighboring spaces of column 1 spaces for bugs
        int nbrBug=0;
        if (grid[0+x][0].isitBug==true)
            nbrBug++;
        if (grid[0+x][2].isitBug==true)
            nbrBug++;
        if ((grid[1+x][1].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][0].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][2].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[x-1][0].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][1].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][2].isitBug==true)&&(x!=0))
            nbrBug++;
        grid[x][1].nbrBugs=nbrBug;
    }
    for (int x=0;x<rows;x++){//Testing neighboring spaces of column 2 spaces for bugs
        int nbrBug=0;
        if (grid[0+x][1].isitBug==true)
            nbrBug++;
        if (grid[0+x][3].isitBug==true)
            nbrBug++;
        if ((grid[1+x][1].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][2].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][3].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[x-1][1].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][2].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][3].isitBug==true)&&(x!=0))
            nbrBug++;
        grid[x][2].nbrBugs=nbrBug;
    }
    for (int x=0;x<rows;x++){//Testing neighboring spaces of column 3 spaces for bugs
        int nbrBug=0;
        if (grid[0+x][2].isitBug==true)
            nbrBug++;
        if (grid[0+x][4].isitBug==true)
            nbrBug++;
        if ((grid[1+x][2].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][3].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][4].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[x-1][2].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][3].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][4].isitBug==true)&&(x!=0))
            nbrBug++;
        grid[x][3].nbrBugs=nbrBug;
    }
    for (int x=0;x<rows;x++){//Testing neighboring spaces of column 4 spaces for bugs
        int nbrBug=0;
        if (grid[0+x][3].isitBug==true)
            nbrBug++;
        if (grid[0+x][5].isitBug==true)
            nbrBug++;
        if ((grid[1+x][3].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][4].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][5].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[x-1][3].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][4].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][5].isitBug==true)&&(x!=0))
            nbrBug++;
        grid[x][4].nbrBugs=nbrBug;
    }
    for (int x=0;x<rows;x++){//Testing neighboring spaces of column 5 spaces for bugs
        int nbrBug=0;
        if (grid[0+x][4].isitBug==true)
            nbrBug++;
        if (grid[0+x][6].isitBug==true)
            nbrBug++;
        if ((grid[1+x][4].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][5].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][6].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[x-1][4].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][5].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][6].isitBug==true)&&(x!=0))
            nbrBug++;
        grid[x][5].nbrBugs=nbrBug;
    }
    for (int x=0;x<rows;x++){//Testing neighboring spaces of column 6 spaces for bugs
        int nbrBug=0;
        if (grid[0+x][5].isitBug==true)
            nbrBug++;
        if (grid[0+x][7].isitBug==true)
            nbrBug++;
        if ((grid[1+x][5].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][6].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][7].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[x-1][5].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][6].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][7].isitBug==true)&&(x!=0))
            nbrBug++;
        grid[x][6].nbrBugs=nbrBug;
    }
    for (int x=0;x<rows;x++){//Testing neighboring spaces of column 7 spaces for bugs
        int nbrBug=0;
        if (grid[0+x][6].isitBug==true)
            nbrBug++;
        if (grid[0+x][8].isitBug==true)
            nbrBug++;
        if ((grid[1+x][6].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][7].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][8].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[x-1][6].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][7].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][8].isitBug==true)&&(x!=0))
            nbrBug++;
        grid[x][7].nbrBugs=nbrBug;
    }
    for (int x=0;x<rows;x++){//Testing neighboring spaces of column 8 spaces for bugs
        int nbrBug=0;
        if (grid[0+x][7].isitBug==true)
            nbrBug++;
        if (grid[0+x][9].isitBug==true)
            nbrBug++;
        if ((grid[1+x][7].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][8].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][9].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[x-1][7].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][8].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][9].isitBug==true)&&(x!=0))
            nbrBug++;
        grid[x][8].nbrBugs=nbrBug;
    }
    for (int x=0;x<rows;x++){//Testing neighboring spaces of column 9 spaces for bugs
        int nbrBug=0;
        if (grid[0+x][8].isitBug==true)
            nbrBug++;
        if ((grid[1+x][8].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[1+x][9].isitBug==true)&&(x!=5))
            nbrBug++;
        if ((grid[x-1][8].isitBug==true)&&(x!=0))
            nbrBug++;
        if ((grid[x-1][9].isitBug==true)&&(x!=0))
            nbrBug++;
        grid[x][9].nbrBugs=nbrBug;
    }
}

void start(string title) {//Displaying start menu to user
    cout<<setw(5)<<" "<<title<<endl;
    cout<<setw(5)<<" "<<"----------"<<endl;
    cout<<"Welcome! Choose an option:"<<endl;
    cout<<"1. Play the Game"<<endl;
    cout<<"2. Change Difficulty"<<endl;
    cout<<"3. Rules"<<endl;
    cout<<"4. Score Keeping"<<endl;   
    cout<<"5. Quit"<<endl;
}

void game(GmeGrid grid[][COLS],//Game function
          int rows,char row,int spot,int nbugs,bool lose,bool win,int &totGame,
          int &gameNum,string name,bool gamesW[],vector<bool> gamesL,int size){
    while(lose!=true&&win!=true){
    display(grid,rows);
    cout<<"Enter in a spot to clear."<<endl;
    cin>>row>>spot;
    cleared(grid,rows,row,spot,nbugs,lose,win,totGame,gameNum,name,gamesW,gamesL,size);
    }
}

void cleared(GmeGrid grid[][COLS],//Clearing a space function
             int rows,char row,int spot,int nbugs,bool &lose,bool &win,int &totGame,
             int &gameNum, string name,bool gamesW[],vector<bool> gamesL,int size){
    nbrBugs(grid,rows);//Calling nbrBugs function to calculate display values
    static int cleared=0;//Static local variable for number of spaces the user has cleared
    if (row=='A'){
        if (grid[0][spot-1].isitBug==true){
            grid[0][spot-1].clrDsp='B';
            lose=true;
            gameNum++;
            gamesL[gameNum]=true;           
            totGame++;
            display(grid,rows);
            cout<<"BUG. YOU LOST."<<endl;
            savRecs(totGame,gameNum,name,gamesW,gamesL,size);
        }
        else {
            cleared++;
            grid[0][spot-1].clrDsp=48+grid[0][spot-1].nbrBugs;
        }
    }
    if (row=='B'){
        if (grid[1][spot-1].isitBug==true){
            grid[1][spot-1].clrDsp='B';
            lose=true;
            gameNum++;
            gamesL[gameNum]=true;  
            totGame++;
            display(grid,rows);
            cout<<"BUG. YOU LOST."<<endl;
            savRecs(totGame,gameNum,name,gamesW,gamesL,size);
        }
        else {
            cleared++;
            grid[1][spot-1].clrDsp=48+grid[1][spot-1].nbrBugs;
        }
    }
    if (row=='C'){
        if (grid[2][spot-1].isitBug==true){
            grid[2][spot-1].clrDsp='B';
            lose=true;
            gameNum++;
            gamesL[gameNum]=true;  
            totGame++;
            display(grid,rows);
            cout<<"BUG. YOU LOST."<<endl;
            savRecs(totGame,gameNum,name,gamesW,gamesL,size);
        }
        else {
            cleared++;
            grid[2][spot-1].clrDsp=48+grid[2][spot-1].nbrBugs;
        }
    }
    if (row=='D'){
        if (grid[3][spot-1].isitBug==true){
            grid[3][spot-1].clrDsp='B';
            lose=true;
            gameNum++;
            gamesL[gameNum]=true;  
            totGame++;
            display(grid,rows);
            cout<<"BUG. YOU LOST."<<endl;
            savRecs(totGame,gameNum,name,gamesW,gamesL,size);
        }
        else {
            cleared++;
            grid[3][spot-1].clrDsp=48+grid[3][spot-1].nbrBugs;
        }
    }
    if (row=='E'){
        if (grid[4][spot-1].isitBug==true){
            grid[4][spot-1].clrDsp='B';
            lose=true;
            gameNum++;
            gamesL[gameNum]=true;  
            totGame++;
            display(grid,rows);
            cout<<"BUG. YOU LOST."<<endl;
            savRecs(totGame,gameNum,name,gamesW,gamesL,size);
        }
        else {
            cleared++;
            grid[4][spot-1].clrDsp=48+grid[4][spot-1].nbrBugs;
        }
    }
    if (row=='F'){
        if (grid[5][spot-1].isitBug==true){
            grid[5][spot-1].clrDsp='B';
            lose=true;
            gameNum++;
            gamesL[gameNum]=true;  
            totGame++;
            display(grid,rows);
            cout<<"BUG. YOU LOST."<<endl;
            savRecs(totGame,gameNum,name,gamesW,gamesL,size);
        }
        else {
            cleared++;
            grid[5][spot-1].clrDsp=48+grid[5][spot-1].nbrBugs;
        }
    }
    if ((cleared+nbugs)==60){//The win condition of the game
        win=true;//If the number of cleared spaces plus number of bugs is equal to 60
                 //Then the user has won the game.
        gameNum++;
        gamesW[gameNum]=true;
        totGame++;
        savRecs(totGame,gameNum,name,gamesW,gamesL,size);
        display(grid,rows);
        cout<<"Congratulations! You have cleared all the bugs. Hooray!!!"<<endl;
    }
}

void display(GmeGrid grid[][COLS],int rows){//Function to display grid.
    for (int x=0;x<rows;x++) {
        for (int y=0;y<COLS;y++){
            cout<<grid[x][y].clrDsp<<" ";
        if (y==9)
            cout<<endl;
        }   
    }
}

int dffclty(){
    static int dffclt=2;//Difficulty for the game
    cout<<"The difficulty is currently "<<dffclt<<"."<<endl;
    cout<<"Select a difficulty to change to:"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"1 - Newbie"<<endl;
    cout<<"2 - Amateur (Default)"<<endl;
    cout<<"3 - Professional"<<endl;
    cin>>dffclt;
    while (dffclt!=1&&dffclt!=2&&dffclt!=3){
        cout<<"Invalid setting. Please enter a valid setting."<<endl;
        cin>>dffclt;
    }
    return dffclt;
}

void rules(GmeGrid grid[][COLS],int rows){//Function to display rules.
    cout<<"Rules"<<endl;
    cout<<"-----"<<endl;
    cout<<"  1 2 3 4 5 6 7 8 9 10"<<endl;
    for (int x=0;x<rows;x++) {
        for (int y=0;y<COLS;y++){
            if (x==0&&y==0)
                cout<<"A ";
            if (x==1&&y==0)
                cout<<"B ";
            if (x==2&&y==0)
                cout<<"C ";
            if (x==3&&y==0)
                cout<<"D ";
            if (x==4&&y==0)
                cout<<"E ";
            if (x==5&&y==0)
                cout<<"F ";
            cout<<"X ";
        if (y==9)
            cout<<endl;
        }   
    }
    cout<<"Enter in a spot you wish to clear."<<endl;
    cout<<"Rows from top to bottom: A B C D E F"<<endl;
    cout<<"Spots are columns 1 2 3 4 5 6 7 8 9 10"<<endl;
    cout<<"For example: Entering A1 would clear the top left corner."<<endl;
    cout<<"The objective of the game is to clear the entire grid without triggering a bug. Have fun!"<<endl;          
}

bool scoreKp(){//Function for prompting user to keep scores
    bool score=false;
    char yesNo;
    cout<<"Would you like to keep score records?"<<endl;
    cout<<"Enter in a Y for yes, and a N for no."<<endl;
    cin>>yesNo;
    yesNo=='Y'?score=true:score=false;
    return score;
}

void savRecs(int &totGame,int gameNum,string name,bool gamesW[],vector<bool> gamesL,int size){//Function to save records
    static int wins=0;
    static int losses=0;
    float average;
    for (int count=1;count<=gameNum;count++){
        if (gamesW[count]==true)
            wins++;
        else if (gamesL[count]==true)
            losses++;
    }
    average=static_cast<float>(wins)/gameNum;
    ofstream outFile;
        outFile.open("totGame.txt");
        outFile<<totGame;
        outFile.close();
        ofstream outfile;
        outfile.open("BugSweeper Records.txt");
        outfile<<"BugSweeper Records"<<endl;
        outfile<<"------------------"<<endl;
        outfile<<name<<endl;
        outfile<<"---------"<<endl;
        outfile<<"Games won                     = "<<wins<<endl;
        outfile<<"Games lost                    = "<<losses<<endl;
        outfile<<"Total Games You Played        = "<<gameNum<<endl;
        outfile<<"Your Average                  = "<<average*100.0f<<"%"<<endl;
        outfile<<"Total Games Played Altogether = "<<totGame<<endl;
        outfile.close();
}

void exit(){//Exit function
    cout<<"You have chosen to exit. See ya!"<<endl;
    exit(0);
}