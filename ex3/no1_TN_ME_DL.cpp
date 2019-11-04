#include <iostream>  // input/output handling
#include <stdio.h>   // for formatted input/output
#include <vector>

 
const int X=10;
const int Y=10;
 
int getRandomNumber(int);
bool getWasTargetHit(int, int, std::vector<std::vector<int> >);
std::vector<std::vector<int> > initializeBoardWithBoats(const int, const int);

int main()
{
 char Spielfeld[Y][X];
 std::vector<std::vector<int> > boardWithBoats=initializeBoardWithBoats(Y,X);
 int x, y;
 char cx, cy;

//Printing the board with boats only to check, that the board is initialized correctly   
/*
printf("  ");
for (x=0; x<X; x++)
    printf("%3d",x+1);
printf("\n\n");
for (y=0; y<Y; y++)
{
    std::cout << (char)('A'+y) << " ";
    std::cout << "  ";
    for (x=0; x<X; x++)
        std::cout << boardWithBoats[y][x] << "  ";
    std::cout << std::endl;
}
std::cout << std::endl;
*/

 for (x=0; x<X; x++)
   for (y=0; y<Y; y++)
     Spielfeld[y][x] = '.';
//
// Anzeige und Eingabe
//
  int xin, yin;
  do {
     printf("  ");
     for (x=0; x<X; x++)
       printf("%3d",x+1);
     printf("\n");
//
     for (y=0; y<Y; y++)
       {
       std::cout << (char)('A'+y) << " ";
       for (x=0; x<X; x++)
         printf("%3c",Spielfeld[y][x]);
       std::cout << std::endl;
       }
//
  std::cout << "your hit: ";
  std::cin >> cy >> xin; //xin input has to be an int, because char only goes up to 9
  if(std::cin.fail())
    break; //when input is not a char followed by an integer, the loop terminates
  
  xin = xin - 1;
  yin = cy - 'A';
  
  if (xin>=0 && xin<X && yin>=0 && yin<Y)
    {
    bool wasTargetHit=getWasTargetHit(yin, xin, boardWithBoats); //Checks, if a boat was hit
    if(wasTargetHit){ 
        Spielfeld[yin][xin] = 'o'; //Hit is marked with "o"
        std::cout << "Target hit!" << std::endl;
    }else{
        Spielfeld[yin][xin] = 'x'; //Miss is marked with "x"
        std::cout << "Target missed!" << std::endl;
    }
    std::cout << std::endl;
    }else
        std::cout << "Point doesn't exist!" << std::endl;
        continue;
    }while (1); //infinite loop
}


int getRandomNumber(int maxNumber)
{
    int randomNumber;
    randomNumber=rand() % maxNumber; //generates number from 0 to maxNumber-1
    return randomNumber;
}

bool getWasTargetHit(int row, int col, std::vector<std::vector<int> > board)
{
    //the function checks if target was hit or not
    bool wasTargetHit=false;
    if(!(board[row][col]==0))
        wasTargetHit=true;
    return wasTargetHit;
}

std::vector<std::vector<int> > initializeBoardWithBoats(const int numberOfRows, const int numberOfColumns)
{
    srand (time(NULL)); //creates random timeseed, so that for every run the seed changes
    std::vector<std::vector<int> > board;
    board=std::vector<std::vector<int> >(numberOfRows,std::vector<int>(numberOfColumns,0));
    int column, row, direction;
    std::vector<int> numberOfBoatsPerKind{ 1,1,1,2,2 }; //Contains how many boats of a kind there are
    std::vector<int> sizeOfBoatsPerKind{ 5,4,3,2,1 }; //Contains the size of each boat
    bool roomForBoat, boatPlaced;
   
    //First, we randomly place the edge of the carrier
    //Definition: 1=carrier, 2=battleship, 3=cruiser, 4=destroyer, 5=submarine
    
    for(int indexBoat=0; indexBoat<numberOfBoatsPerKind.size(); indexBoat++){
        for(int j=0; j<numberOfBoatsPerKind[indexBoat]; j++){
            boatPlaced=false;
            while(!boatPlaced){ //if a boat was placed someway, the bool is true and the infinite loop terminates
                column=getRandomNumber(numberOfColumns);
                row=getRandomNumber(numberOfRows);
               /* I set direction to down and right as a default.
                * When there is not enough room down and right or it is 
                * already occupied, the boat will be placed to the opposite side.
                * Example: Let's say the program wants to place a battleship at row=8, column=9 horizontal.
                *          Then it checks if the 3 points right to (8,2) are existing and if so, 
                *          checks if another boat occupies one of the 32 points. In this case there
                *          are no 3 points on the right side of (8,2) so it checks whether a boat occupies
                *          the left 3 points. If that's not the case, it places the boat. Otherwise it randomly
                *          creates a new point (row,column).
                * I start by placing a carrier, then a battleship, cruiser, 2 destroyers, 2 submarines.
                */
                direction=getRandomNumber(2); //0 is vertical, 1 is horizontal
                roomForBoat=true; //stays true, if room is there, if not, gets overwritten with false
                if(direction==1){
                    if(numberOfColumns-column>=sizeOfBoatsPerKind[indexBoat]){ //checks if enough points are right to the random point
                        for(int i=0; i<sizeOfBoatsPerKind[indexBoat]; i++){
                            if(board[row][column+i]!=0) //checks if another boat is on one of the points
                                roomForBoat=false;
                        }
                        if(roomForBoat){ 
                            for(int i=0; i<sizeOfBoatsPerKind[indexBoat]; i++)
                                board[row][column+i]=indexBoat + 1; //places boat with indexBoat
                            boatPlaced=true;
                        }
                    }else{ //same as above but going left
                        for(int i=0; i<sizeOfBoatsPerKind[indexBoat]; i++){ 
                            if(!(board[row][column-i]==0))
                                roomForBoat=false;
                        }
                        if(roomForBoat){
                            for(int i=0; i<sizeOfBoatsPerKind[indexBoat]; i++)
                                board[row][column-i]=indexBoat + 1;
                            boatPlaced=true;
                        }
                    }            
                }else{ //same as above but going down/up
                    if(numberOfRows-row>=sizeOfBoatsPerKind[indexBoat]){
                        for(int i=0; i<sizeOfBoatsPerKind[indexBoat]; i++){
                            if(board[row+i][column]!=0)
                                roomForBoat=false;
                        }
                        if(roomForBoat){
                            for(int i=0; i<sizeOfBoatsPerKind[indexBoat]; i++)
                                board[row+i][column]=indexBoat + 1;
                            boatPlaced=true;
                    }
                    }else{
                        for(int i=0; i<sizeOfBoatsPerKind[indexBoat]; i++){
                            if(!(board[row-i][column]==0))
                                roomForBoat=false;
                        }
                        if(roomForBoat){
                            for(int i=0; i<sizeOfBoatsPerKind[indexBoat]; i++)
                                board[row-i][column]=indexBoat + 1;
                            boatPlaced=true;
                        }
                    }
                }
            }
        }
    }
    return board;

}