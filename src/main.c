#include <stdio.h> 
#include <stdlib.h> 
#include "../include/logic.h"
#include "../include/io.h"
#include "../include/wincheck.h"
#include <string.h> 

int main(){
    Node board[24][24]; 
    int uid=1; 
    for (int x=0;24>x;x++){
        for (int y=0; 24>y;y++){
            board[x][y]= createNode(x,y,uid); 
            uid++;
        }
    }
    int turn = 1; 
    while(1){


        printBoard(board);
        char colour[10];
        if (turn==-1){strncpy(colour,"Black",sizeof(colour));}
        else if (turn==1){strncpy(colour,"Red",sizeof(colour));}

        int coords[2]; 
        getTurn(colour,coords);
        int valid = checkValid(board,coords); 
        if (valid){
            doMove(board,coords,turn); 
            turn*=-1; 
            if (turn==-1){strncpy(colour,"Black",sizeof(colour));}
            else if (turn==1){strncpy(colour,"Red",sizeof(colour));}

            printBoard(board);

            int win_status = checkWin(board); 
            if (win_status==1){
                win("Red");
            }
            else if (win_status==-1){
                win("Black");
            }
        }
        else{

        }

    }
}