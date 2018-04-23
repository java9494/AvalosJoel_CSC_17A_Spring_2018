/* 
 * File:   main.cpp
 * Author: Joel Avalos
 * Created on April 22, 2018, 1:13 PM
 * Purpose: Create a full version of MineSweeper, using concepts from 
 * Chapter 9-12 of Gaddis.
 * v1: Created structures to condense game variables into.
 * v2: Created a difficulty modifier using 2-D pointers.
 * v3: Added reading/writing concepts and string library functions.
 */
 
//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cctype>

#include "GStates.h"
#include "GmeGrid.h"
#include "GmeStat.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions
const int COLS1=5;//Constant for no. of cols in 2-D Array (newbie setting & extra cols for pro setting)
const int COLS=10;//Constant for the number of columns in the 2-D Array (default)

//Function Prototypes
void random(GmeGrid [][COLS],int,bool [],const int,int**,int,GmeGrid [][COLS1]);//Function to randomize each spot on grid.
void bugTest(GmeGrid [][COLS],int,GmeGrid [][COLS1],int,int**);//Function to test whether a spot is a bug.
int nbrBug(GmeGrid [][COLS],int,GmeGrid[][COLS1],int);//Function to calculate number of Bugs on grid
                            //A well as to activate Bug spaces.
void nbrBugs(GmeGrid [][COLS],int,GmeGrid [][COLS1],int);//Function to calculate neighboring bugs around each space
void start (string);//Function to run the game's Start Menu
void start (GmeGrid [][COLS],int);
void game(GmeGrid [][COLS],int,char,int,int,bool,bool,
        int &,int &,string,bool [],vector<bool>,int,int**,GmeGrid[][COLS1],int);//Function to run the game
void cleared(GmeGrid [][COLS],
        int,char,int,int,bool &,bool &,int &,int &,string,bool [],vector<bool>,int,
        int**,GmeGrid [][COLS1],int);//Function to clear each user-inputted space
void display(GmeGrid [][COLS],int,GmeGrid [][COLS1],int);//Function for displaying the grid.
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
    GmeGrid grid[ROWS][COLS];//Structure for default game grid
    GmeGrid xtraGrd[ROWS][COLS1];//Structure for newbie and exta pro spaces grid
    GmeStat gamest = {0,0,0,0,0};
    int nBugs;//The total number of bugs in the game
    const int MXGAMES=100;//Max number of games to record keep is 100
    bool gamesW[MXGAMES];//Array to hold number of games won
    vector<bool> gamesL(MXGAMES,false);//Vector to hold number of games lost
    int gameNum=0;//Count of how many games user has played
    int totGame;//Total games played
    int dff=2;//Game difficulty variable set to default setting
    int **proGrid;
    bool deleetC=false;//Check if dyn memory was deleted beforehand
    bool dynChk=false;//Check if dyn memory was allocated
 
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
                random(grid,ROWS,gamesW,MXGAMES,proGrid,dff,xtraGrd);//Call random function to randomize the grid
            }
            if (dff==3||dff==1){
                int **proGrid=new int*[ROWS];//Pointer used to allocate memory for a bigger grid
                     for (int i=0;i<ROWS;i++){
                         proGrid[i]=new int[COLS1];
                     }
                         random(grid,ROWS,gamesW,MXGAMES,proGrid,dff,xtraGrd);//Call random function to randomize the grid
                    for (int x=0;x<ROWS;x++){//Arming bugs on extra grid
                        for (int y=0;y<COLS1;y++){
                            if (proGrid[x][y]%3==0){//Bug criteria: if the random number
                                                 //Assigned to a space is cleanly divisible by 3
                                                 //(no remainder), then that space is a bug
                                xtraGrd[x][y].isitBug=true;//Set bug test to true      
                            }
                        }
                    }
                dynChk=true;//Flag for dynamic allocation
            }
            //Initializing the Bugs
            bugTest(grid,ROWS,xtraGrd,dff,proGrid);//Call the bugTest function to arm bugs
            nBugs=nbrBug(grid,ROWS,xtraGrd,dff);//Call nBug function to add up the total number of bugs in the game.
                /*for (int x=0;x<ROWS;x++){//Loop to display the grid with bug locations for debugging purposes
                for (int y=0;y<COLS;y++){
                    cout<<isitBug[x][y]<<" ";
                    if (y==9)
                        cout<<endl;
                }
            }*/
                game(grid,ROWS,row,spot,nBugs,gmeStrt.gameWin,gmeStrt.gameLss,
                totGame,gameNum,name,gamesW,gamesL,MXGAMES,proGrid,xtraGrd,dff);//Run game
                if (dynChk==true){//Deleting dyn allocated memory after end of game    
                    for (int i=0;i<ROWS;i++){
                        delete [] proGrid[i];
                    }
                deleetC=true;
                }
            break;
        case 2: dff=dffclty();break;//Difficulty modifier
        case 3: rules(grid,ROWS);break;//Display rules
        case 4: gmeStrt.scores=scoreKp();//Option to keep records
        if (gmeStrt.scores){
        cout<<"Please enter a name."<<endl;
        cin>>name;
        }
        break;
        default: {
            if (deleetC!=true&&dynChk==true){//In case dyn memory has not be freed
                cout<<"Hi"<<endl;
                for (int i=0;i<ROWS;i++){
                    delete [] proGrid[i];
                }
                delete [] proGrid;
            }
            exit();break;//Or, exit program
        }        
    }
    }while (in==1||in==2||in==3||in==4);//Display menu while user inputs menu choices 1 or 2
 
    //Exit stage right!
    return 0;
}
    
void random (GmeGrid grid[][COLS],int rows,bool gamesW[],const int MXGAMES,int **proGrid,int dff,GmeGrid xtraGrd[][COLS1]){//Randomizing the grid.
    for (int x=0;x<rows;x++){
        for (int y=0;y<COLS;y++){
            grid[x][y].spots=rand();//Going through every element in array to randomize
        }
    }
    for (int x=0;x<rows;x++){//Loop to set each space's initial Bug value to false
            for (int y=0;y<COLS;y++){
                grid[x][y].isitBug=false;
            }
        }
        for (int x=0;x<rows;x++){//Loop to set each space's initial display to an X
            for (int y=0;y<COLS;y++){
                grid[x][y].clrDsp='X';
            }
        }
        for (int x=0;x<MXGAMES;x++){//Loop to set game wins to false
            gamesW[x]=false;
        }
    if (dff==3||dff==1){
        for (int x=0;x<rows;x++){//Randomizing extra grid
            for (int y=0;y<COLS1;y++){
                proGrid[x][y]=rand();
            }
        }
        for (int x=0;x<rows;x++){//Loop to set each space's initial Bug value to false
                for (int y=0;y<COLS;y++){
                    xtraGrd[x][y].isitBug=false;
                }
            }
        for (int x=0;x<rows;x++){//Loop to set each space's initial display to an X
            for (int y=0;y<COLS;y++){
                xtraGrd[x][y].clrDsp='X';
            }
        }
    }
}

void bugTest(GmeGrid grid[][COLS],int rows,GmeGrid xtraGrd[][COLS1],int dff,int **proGrid){//Testing each space for bugs.
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

int nbrBug(GmeGrid grid[][COLS],int rows,GmeGrid xtraGrd[][COLS1],int dff){//Adding up the number of bugs on the grid
    int nbugs=0;
    if (dff==1){
        for (int x=0;x<rows;x++){
            for (int y=0;y<COLS1;y++){
                if (xtraGrd[x][y].isitBug==true){//Checking bool value for bug
                    nbugs++;//Counting number of bugs for the win condition
                }
            }
        }
        return nbugs;
    }
    else {
        for (int x=0;x<rows;x++){
            for (int y=0;y<COLS;y++){
                if (grid[x][y].isitBug==true){//Checking bool value for bug
                    nbugs++;//Counting number of bugs for the win condition
                }
            }
        }
        if (dff==3){
            for (int x=0;x<rows;x++){
                for (int y=0;y<COLS1;y++){
                    if (xtraGrd[x][y].isitBug==true){//Checking bool value for bug
                        nbugs++;//Counting number of bugs for the win condition
                    }
                }
            }
        }
    }
    return nbugs;
}

void nbrBugs(GmeGrid grid[][COLS],int rows,GmeGrid xtraGrd[][COLS1],int dff){//Testing neighboring
                                                            //spaces on grid for bugs
    if (dff==1){
        for (int x=0;x<rows;x++){//Testing neighboring spaces of column 0 spaces for bugs
            int nbrBug=0;
            if (xtraGrd[0+x][1].isitBug==true)
                nbrBug++;
            if ((xtraGrd[1+x][0].isitBug==true)&&(x!=5))
                nbrBug++;
            if ((xtraGrd[1+x][1].isitBug==true)&&(x!=5))
                nbrBug++;
            if ((xtraGrd[x-1][0].isitBug==true)&&(x!=0))
                nbrBug++;
            if ((xtraGrd[x-1][1].isitBug==true)&&(x!=0))
                nbrBug++;
            xtraGrd[x][0].nbrBugs=nbrBug;
        }
        for (int x=0;x<rows;x++){//Testing neighboring spaces of column 1 spaces for bugs
            int nbrBug=0;
            if (xtraGrd[0+x][0].isitBug==true)
                nbrBug++;
            if (xtraGrd[0+x][2].isitBug==true)
                nbrBug++;
            if ((xtraGrd[1+x][1].isitBug==true)&&(x!=5))
                nbrBug++;
            if ((xtraGrd[1+x][0].isitBug==true)&&(x!=5))
                nbrBug++;
            if ((xtraGrd[1+x][2].isitBug==true)&&(x!=5))
                nbrBug++;
            if ((xtraGrd[x-1][0].isitBug==true)&&(x!=0))
                nbrBug++;
            if ((xtraGrd[x-1][1].isitBug==true)&&(x!=0))
                nbrBug++;
            if ((xtraGrd[x-1][2].isitBug==true)&&(x!=0))
                nbrBug++;
            xtraGrd[x][1].nbrBugs=nbrBug;
        }
        for (int x=0;x<rows;x++){//Testing neighboring spaces of column 2 spaces for bugs
            int nbrBug=0;
            if (xtraGrd[0+x][1].isitBug==true)
                nbrBug++;
            if (xtraGrd[0+x][3].isitBug==true)
                nbrBug++;
            if ((xtraGrd[1+x][1].isitBug==true)&&(x!=5))
                nbrBug++;
            if ((xtraGrd[1+x][2].isitBug==true)&&(x!=5))
                nbrBug++;
            if ((xtraGrd[1+x][3].isitBug==true)&&(x!=5))
                nbrBug++;
            if ((xtraGrd[x-1][1].isitBug==true)&&(x!=0))
                nbrBug++;
            if ((xtraGrd[x-1][2].isitBug==true)&&(x!=0))
                nbrBug++;
            if ((xtraGrd[x-1][3].isitBug==true)&&(x!=0))
                nbrBug++;
            xtraGrd[x][2].nbrBugs=nbrBug;
        }
        for (int x=0;x<rows;x++){//Testing neighboring spaces of column 3 spaces for bugs
            int nbrBug=0;
            if (xtraGrd[0+x][2].isitBug==true)
                nbrBug++;
            if (xtraGrd[0+x][4].isitBug==true)
                nbrBug++;
            if ((xtraGrd[1+x][2].isitBug==true)&&(x!=5))
                nbrBug++;
            if ((xtraGrd[1+x][3].isitBug==true)&&(x!=5))
                nbrBug++;
            if ((xtraGrd[1+x][4].isitBug==true)&&(x!=5))
                nbrBug++;
            if ((xtraGrd[x-1][2].isitBug==true)&&(x!=0))
                nbrBug++;
            if ((xtraGrd[x-1][3].isitBug==true)&&(x!=0))
                nbrBug++;
            if ((xtraGrd[x-1][4].isitBug==true)&&(x!=0))
                nbrBug++;
            xtraGrd[x][3].nbrBugs=nbrBug;
        }
        for (int x=0;x<rows;x++){//Testing neighboring spaces of column 4 spaces for bugs
            int nbrBug=0;
            if (xtraGrd[0+x][3].isitBug==true)//Space to immediate left
                nbrBug++;
            if ((xtraGrd[1+x][3].isitBug==true)&&(x!=5))//Space diagonally left below
                nbrBug++;
            if ((xtraGrd[1+x][4].isitBug==true)&&(x!=5))//Space immediately below
                nbrBug++;
            if ((xtraGrd[x-1][3].isitBug==true)&&(x!=0))//Space diagonally left above
                nbrBug++;
            if ((xtraGrd[x-1][4].isitBug==true)&&(x!=0))//Space directly below
                nbrBug++;
            xtraGrd[x][4].nbrBugs=nbrBug;
        }
    }
    else {
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
            grid[x][0].nbrBugs=nbrBug;
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
        if (dff==3){//Testing additional spaces of the Pro difficulty grid
            for (int x=0;x<rows;x++){//Testing neighboring spaces of column 10 spaces for bugs
            int nbrBug=0;
            if (grid[0+x][9].isitBug==true)//Space to immediate left
                nbrBug++;
            if (xtraGrd[0+x][1].isitBug==true)//Space to immediate right
                nbrBug++;
            if ((grid[1+x][9].isitBug==true)&&(x!=5))//Space diagonally left below
                nbrBug++;
            if ((xtraGrd[1+x][0].isitBug==true)&&(x!=5))//Space directly below
                nbrBug++;
            if ((xtraGrd[1+x][1].isitBug==true)&&(x!=5))//Space diagonally right below
                nbrBug++;
            if ((grid[x-1][9].isitBug==true)&&(x!=0))//Space diagonally left above
                nbrBug++;
            if ((xtraGrd[x-1][1].isitBug==true)&&(x!=0))//Space diagonally right above
                nbrBug++;
            if ((xtraGrd[x-1][0].isitBug==true)&&(x!=0))//Space directly above
                nbrBug++;
            xtraGrd[x][0].nbrBugs=nbrBug;
            }
            for (int x=0;x<rows;x++){//Testing neighboring spaces of column 11 spaces for bugs
            int nbrBug=0;
            if (xtraGrd[0+x][0].isitBug==true)//Space to immediate left
                nbrBug++;
            if (xtraGrd[0+x][2].isitBug==true)//Space to immediate right
                nbrBug++;
            if ((xtraGrd[1+x][0].isitBug==true)&&(x!=5))//Space diagonally left below
                nbrBug++;
            if ((xtraGrd[1+x][1].isitBug==true)&&(x!=5))//Space directly below
                nbrBug++;
            if ((xtraGrd[1+x][2].isitBug==true)&&(x!=5))//Space diagonally right below
                nbrBug++;
            if ((xtraGrd[x-1][0].isitBug==true)&&(x!=0))//Space diagonally above left
                nbrBug++;
            if ((xtraGrd[x-1][1].isitBug==true)&&(x!=0))//Space directly above
                nbrBug++;
            if ((xtraGrd[x-1][2].isitBug==true)&&(x!=0))//Space diagonally right above
                nbrBug++;
            xtraGrd[x][1].nbrBugs=nbrBug;
            }
            for (int x=0;x<rows;x++){//Testing neighboring spaces of column 12 spaces for bugs
            int nbrBug=0;
            if (xtraGrd[0+x][1].isitBug==true)//Space to immediate left
                nbrBug++;
            if (xtraGrd[0+x][3].isitBug==true)//Space to immediate right
                nbrBug++;
            if ((xtraGrd[1+x][1].isitBug==true)&&(x!=5))//Space diagonally left below
                nbrBug++;
            if ((xtraGrd[1+x][2].isitBug==true)&&(x!=5))//Space directly below
                nbrBug++;
            if ((xtraGrd[1+x][3].isitBug==true)&&(x!=5))//Space diagonally right below
                nbrBug++;
            if ((xtraGrd[x-1][1].isitBug==true)&&(x!=0))//Space diagonally above left
                nbrBug++;
            if ((xtraGrd[x-1][2].isitBug==true)&&(x!=0))//Space directly above
                nbrBug++;
            if ((xtraGrd[x-1][3].isitBug==true)&&(x!=0))//Space diagonally right above
                nbrBug++;
            xtraGrd[x][2].nbrBugs=nbrBug;
            }
            for (int x=0;x<rows;x++){//Testing neighboring spaces of column 13 spaces for bugs
            int nbrBug=0;
            if (xtraGrd[0+x][2].isitBug==true)//Space to immediate left
                nbrBug++;
            if (xtraGrd[0+x][4].isitBug==true)//Space to immediate right
                nbrBug++;
            if ((xtraGrd[1+x][2].isitBug==true)&&(x!=5))//Space diagonally left below
                nbrBug++;
            if ((xtraGrd[1+x][3].isitBug==true)&&(x!=5))//Space directly below
                nbrBug++;
            if ((xtraGrd[1+x][4].isitBug==true)&&(x!=5))//Space diagonally right below
                nbrBug++;
            if ((xtraGrd[x-1][2].isitBug==true)&&(x!=0))//Space diagonally above left
                nbrBug++;
            if ((xtraGrd[x-1][3].isitBug==true)&&(x!=0))//Space directly above
                nbrBug++;
            if ((xtraGrd[x-1][4].isitBug==true)&&(x!=0))//Space diagonally right above
                nbrBug++;
            xtraGrd[x][3].nbrBugs=nbrBug;
            }
            for (int x=0;x<rows;x++){//Testing neighboring spaces of column 14 spaces for bugs
            int nbrBug=0;
            if (xtraGrd[0+x][3].isitBug==true)//Space to immediate left
                nbrBug++;
            if ((xtraGrd[1+x][3].isitBug==true)&&(x!=5))//Space diagonally left below
                nbrBug++;
            if ((xtraGrd[1+x][4].isitBug==true)&&(x!=5))//Space immediately below
                nbrBug++;
            if ((xtraGrd[x-1][3].isitBug==true)&&(x!=0))//Space diagonally left above
                nbrBug++;
            if ((xtraGrd[x-1][4].isitBug==true)&&(x!=0))//Space directly below
                nbrBug++;
            xtraGrd[x][4].nbrBugs=nbrBug;
            }
        }
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
          int &gameNum,string name,bool gamesW[],vector<bool> gamesL,int size,int **proGrid,GmeGrid xtraGrd[][COLS1],int dff){
    while(lose!=true&&win!=true){
    display(grid,rows,xtraGrd,dff);
    cout<<"Enter in a spot to clear."<<endl;
    cin>>row>>spot; 
    while (toupper(row)!='A'&&toupper(row)!='B'&&toupper(row) !='C'&&toupper(row)!='D'&&toupper(row)!='E'&&toupper(row)!='F'){//Validating input
        cout<<"Not a valid input for row, please enter a row A-F"<<endl;
        cin>>row>>spot;
    }
    if (islower(row)){//Converting lowercase row inputs to upper case
        row=toupper(row);
    }
    cout<<row<<endl;
    cleared(grid,rows,row,spot,nbugs,lose,win,totGame,gameNum,name,gamesW,gamesL,size,proGrid,xtraGrd,dff);
    } 
}

void cleared(GmeGrid grid[][COLS],//Clearing a space function
             int rows,char row,int spot,int nbugs,bool &lose,bool &win,int &totGame,
             int &gameNum, string name,bool gamesW[],vector<bool> gamesL,int size,
             int **proGrid,GmeGrid xtraGrd[][COLS1],int dff){
    nbrBugs(grid,rows,xtraGrd,dff);//Calling nbrBugs function to calculate display values
    static int cleared=0;//Static local variable for number of spaces the user has cleared
    if (row=='A'||toupper(row)=='A'){
        if (dff==1){
            if (xtraGrd[0][spot-1].isitBug==true){
            xtraGrd[0][spot-1].clrDsp='B';
            lose=true;
            gameNum++;
            gamesL[gameNum]=true;           
            totGame++;
            display(grid,rows,xtraGrd,dff);
            cout<<"BUG. YOU LOST."<<endl;
            savRecs(totGame,gameNum,name,gamesW,gamesL,size);
            }
            else {
            cleared++;
            xtraGrd[0][spot-1].clrDsp=48+xtraGrd[0][spot-1].nbrBugs;
            }
        }
        else {
            if (dff==3&&(spot==11||spot==12||spot==13||spot==14||spot==15)){
                spot-=10;
                if (xtraGrd[0][spot-1].isitBug==true){
                xtraGrd[0][spot-1].clrDsp='B';
                lose=true;
                gameNum++;
                gamesL[gameNum]=true;           
                totGame++;
                display(grid,rows,xtraGrd,dff);
                cout<<"BUG. YOU LOST."<<endl;
                savRecs(totGame,gameNum,name,gamesW,gamesL,size);
                }
                else {
                cleared++;
                xtraGrd[0][spot-1].clrDsp=48+xtraGrd[0][spot-1].nbrBugs;
                }
            }
            else if (grid[0][spot-1].isitBug==true){
                grid[0][spot-1].clrDsp='B';
                lose=true;
                gameNum++;
                gamesL[gameNum]=true;           
                totGame++;
                display(grid,rows,xtraGrd,dff);
                cout<<"BUG. YOU LOST."<<endl;
                savRecs(totGame,gameNum,name,gamesW,gamesL,size);
            }
            else {
                cleared++;
                grid[0][spot-1].clrDsp=48+grid[0][spot-1].nbrBugs;
            }
        }
    }
    if (row=='B'||toupper(row)=='B'){
        if (dff==1){
            if (xtraGrd[1][spot-1].isitBug==true){
            xtraGrd[1][spot-1].clrDsp='B';
            lose=true;
            gameNum++;
            gamesL[gameNum]=true;           
            totGame++;
            display(grid,rows,xtraGrd,dff);
            cout<<"BUG. YOU LOST."<<endl;
            savRecs(totGame,gameNum,name,gamesW,gamesL,size);
            }
            else {
            cleared++;
            xtraGrd[1][spot-1].clrDsp=48+xtraGrd[1][spot-1].nbrBugs;
            }
        }
        else {
            if (dff==3&&(spot==11||spot==12||spot==13||spot==14||spot==15)){
                spot-=10;
                if (xtraGrd[1][spot-1].isitBug==true){
                xtraGrd[1][spot-1].clrDsp='B';
                lose=true;
                gameNum++;
                gamesL[gameNum]=true;           
                totGame++;
                display(grid,rows,xtraGrd,dff);
                cout<<"BUG. YOU LOST."<<endl;
                savRecs(totGame,gameNum,name,gamesW,gamesL,size);
                }
            else {
            cleared++;
            xtraGrd[1][spot-1].clrDsp=48+xtraGrd[1][spot-1].nbrBugs;
            }
            }
            else if (grid[1][spot-1].isitBug==true){
                grid[1][spot-1].clrDsp='B';
                lose=true;
                gameNum++;
                gamesL[gameNum]=true;  
                totGame++;
                display(grid,rows,xtraGrd,dff);
                cout<<"BUG. YOU LOST."<<endl;
                savRecs(totGame,gameNum,name,gamesW,gamesL,size);
            }
            else {
                cleared++;
                grid[1][spot-1].clrDsp=48+grid[1][spot-1].nbrBugs;
            }
        }
    }
    if (row=='C'||toupper(row)=='C'){
        if (dff==1){
            if (xtraGrd[2][spot-1].isitBug==true){
            xtraGrd[2][spot-1].clrDsp='B';
            lose=true;
            gameNum++;
            gamesL[gameNum]=true;           
            totGame++;
            display(grid,rows,xtraGrd,dff);
            cout<<"BUG. YOU LOST."<<endl;
            savRecs(totGame,gameNum,name,gamesW,gamesL,size);
            }
            else {
            cleared++;
            xtraGrd[2][spot-1].clrDsp=48+xtraGrd[2][spot-1].nbrBugs;
            }
        }
        else {
            if (dff==3&&(spot==11||spot==12||spot==13||spot==14||spot==15)){
                spot-=10;
                if (xtraGrd[2][spot-1].isitBug==true){
                xtraGrd[2][spot-1].clrDsp='B';
                lose=true;
                gameNum++;
                gamesL[gameNum]=true;           
                totGame++;
                display(grid,rows,xtraGrd,dff);
                cout<<"BUG. YOU LOST."<<endl;
                savRecs(totGame,gameNum,name,gamesW,gamesL,size);
                }
                else {
                cleared++;
                xtraGrd[2][spot-1].clrDsp=48+xtraGrd[2][spot-1].nbrBugs;
                }
            }
            else if (grid[2][spot-1].isitBug==true){
                grid[2][spot-1].clrDsp='B';
                lose=true;
                gameNum++;
                gamesL[gameNum]=true;  
                totGame++;
                display(grid,rows,xtraGrd,dff);
                cout<<"BUG. YOU LOST."<<endl;
                savRecs(totGame,gameNum,name,gamesW,gamesL,size);
            }
            else {
                cleared++;
                grid[2][spot-1].clrDsp=48+grid[2][spot-1].nbrBugs;
            }
        }
    }
    if (row=='D'||toupper(row)=='D'){
        if (dff==1){
            if (xtraGrd[3][spot-1].isitBug==true){
            xtraGrd[3][spot-1].clrDsp='B';
            lose=true;
            gameNum++;
            gamesL[gameNum]=true;           
            totGame++;
            display(grid,rows,xtraGrd,dff);
            cout<<"BUG. YOU LOST."<<endl;
            savRecs(totGame,gameNum,name,gamesW,gamesL,size);
            }
            else {
            cleared++;
            xtraGrd[3][spot-1].clrDsp=48+xtraGrd[3][spot-1].nbrBugs;
            }
        }
        else {
            if (dff==3&&(spot==11||spot==12||spot==13||spot==14||spot==15)){
                spot-=10;
                if (xtraGrd[3][spot-1].isitBug==true){
                xtraGrd[3][spot-1].clrDsp='B';
                lose=true;
                gameNum++;
                gamesL[gameNum]=true;           
                totGame++;
                display(grid,rows,xtraGrd,dff);
                cout<<"BUG. YOU LOST."<<endl;
                savRecs(totGame,gameNum,name,gamesW,gamesL,size);
                }
                else {
                cleared++;
                xtraGrd[3][spot-1].clrDsp=48+xtraGrd[3][spot-1].nbrBugs;
                }
            }
            else if (grid[3][spot-1].isitBug==true){
                grid[3][spot-1].clrDsp='B';
                lose=true;
                gameNum++;
                gamesL[gameNum]=true;  
                totGame++;
                display(grid,rows,xtraGrd,dff);
                cout<<"BUG. YOU LOST."<<endl;
                savRecs(totGame,gameNum,name,gamesW,gamesL,size);
            }
            else {
                cleared++;
                grid[3][spot-1].clrDsp=48+grid[3][spot-1].nbrBugs;
            }
        }
    }
    if (row=='E'||toupper(row)=='E'){
        if (dff==1){
            if (xtraGrd[4][spot-1].isitBug==true){
            xtraGrd[4][spot-1].clrDsp='B';
            lose=true;
            gameNum++;
            gamesL[gameNum]=true;           
            totGame++;
            display(grid,rows,xtraGrd,dff);
            cout<<"BUG. YOU LOST."<<endl;
            savRecs(totGame,gameNum,name,gamesW,gamesL,size);
            }
            else {
            cleared++;
            xtraGrd[4][spot-1].clrDsp=48+xtraGrd[4][spot-1].nbrBugs;
            }
        }
        else {
            if (dff==3&&(spot==11||spot==12||spot==13||spot==14||spot==15)){
                spot-=10;
                if (xtraGrd[4][spot-1].isitBug==true){
                xtraGrd[4][spot-1].clrDsp='B';
                lose=true;
                gameNum++;
                gamesL[gameNum]=true;           
                totGame++;
                display(grid,rows,xtraGrd,dff);
                cout<<"BUG. YOU LOST."<<endl;
                savRecs(totGame,gameNum,name,gamesW,gamesL,size);
                }
                else {
                cleared++;
                xtraGrd[4][spot-1].clrDsp=48+xtraGrd[4][spot-1].nbrBugs;
                }
            }
            else if (grid[4][spot-1].isitBug==true){
                grid[4][spot-1].clrDsp='B';
                lose=true;
                gameNum++;
                gamesL[gameNum]=true;  
                totGame++;
                display(grid,rows,xtraGrd,dff);
                cout<<"BUG. YOU LOST."<<endl;
                savRecs(totGame,gameNum,name,gamesW,gamesL,size);
            }
            else {
                cleared++;
                grid[4][spot-1].clrDsp=48+grid[4][spot-1].nbrBugs;
            }
        }
    }
    if (row=='F'||toupper(row)=='F'){
        if (dff==1){
            if (xtraGrd[5][spot-1].isitBug==true){
            xtraGrd[5][spot-1].clrDsp='B';
            lose=true;
            gameNum++;
            gamesL[gameNum]=true;           
            totGame++;
            display(grid,rows,xtraGrd,dff);
            cout<<"BUG. YOU LOST."<<endl;
            savRecs(totGame,gameNum,name,gamesW,gamesL,size);
            }
            else {
            cleared++;
            xtraGrd[5][spot-1].clrDsp=48+xtraGrd[5][spot-1].nbrBugs;
            }
        }
        else {
            if (dff==3&&(spot==11||spot==12||spot==13||spot==14||spot==15)){
                spot-=10;
                if (xtraGrd[5][spot-1].isitBug==true){
                xtraGrd[5][spot-1].clrDsp='B';
                lose=true;
                gameNum++;
                gamesL[gameNum]=true;           
                totGame++;
                display(grid,rows,xtraGrd,dff);
                cout<<"BUG. YOU LOST."<<endl;
                savRecs(totGame,gameNum,name,gamesW,gamesL,size);
                }
                else {
                cleared++;
                xtraGrd[5][spot-1].clrDsp=48+xtraGrd[5][spot-1].nbrBugs;
                }
            }
            else if (grid[5][spot-1].isitBug==true){
                grid[5][spot-1].clrDsp='B';
                lose=true;
                gameNum++;
                gamesL[gameNum]=true;  
                totGame++;
                display(grid,rows,xtraGrd,dff);
                cout<<"BUG. YOU LOST."<<endl;
                savRecs(totGame,gameNum,name,gamesW,gamesL,size);
            }
            else {
                cleared++;
                grid[5][spot-1].clrDsp=48+grid[5][spot-1].nbrBugs;
            }
        }
    }
    if ((dff==1)&&(cleared+nbugs)==30){
        win=true;//If the number of cleared spaces plus number of bugs is equal to 60
                 //Then the user has won the game.
        gameNum++;
        gamesW[gameNum]=true;
        totGame++;
        savRecs(totGame,gameNum,name,gamesW,gamesL,size);
        display(grid,rows,xtraGrd,dff);
        cout<<"Congratulations! You have cleared all the bugs. Hooray!!!"<<endl;
    }
    else if (((cleared+nbugs)==60)||((cleared+nbugs)==90)){//The win condition of the game
        win=true;//If the number of cleared spaces plus number of bugs is equal to 60
                 //Then the user has won the game.
        gameNum++;
        gamesW[gameNum]=true;
        totGame++;
        savRecs(totGame,gameNum,name,gamesW,gamesL,size);
        display(grid,rows,xtraGrd,dff);
        cout<<"Congratulations! You have cleared all the bugs. Hooray!!!"<<endl;
    }
}

void display(GmeGrid grid[][COLS],int rows,GmeGrid xtraGrd[][COLS1],int dff){//Function to display grid.
    if (dff==1){
        for (int x=0;x<rows;x++) {
            for (int y=0;y<COLS1;y++){
                cout<<xtraGrd[x][y].clrDsp<<" ";
            if (y==4)
                cout<<endl;
            }   
        }
    }
    if (dff==2){
        for (int x=0;x<rows;x++) {
            for (int y=0;y<COLS;y++){
                cout<<grid[x][y].clrDsp<<" ";
            if (y==9)
                cout<<endl;
            }   
        }
    }
    if (dff==3){
        for (int x=0;x<rows;x++) {
            for (int y=0;y<(COLS+COLS1);y++){
                if (y<10)
                cout<<grid[x][y].clrDsp<<" ";
                if (y>=10)
                    cout<<xtraGrd[x][y-10].clrDsp<<" ";
                if (y==14)
                cout<<endl;
            }   
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
        outfile<<fixed;
        outfile<<setprecision(2);
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