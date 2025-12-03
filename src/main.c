#include <stdio.h> 
#include <stdlib.h> 
#include "../include/logic.h"
#include "../include/io.h"
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
    printBoard(board);
    while(1){


        char colour[10];
        if (turn==-1){strncpy(colour,"Black",sizeof(colour));}
        else if (turn==1){strncpy(colour,"Red",sizeof(colour));}

        int coords[2]; 
        getTurn(colour,coords);
        int valid = checkValid(board,coords); 
        if ((turn==-1&&coords[0]==0)||(turn==-1&&coords[0]==23)){valid=0;printf("Invalid input, You cannot place a peg in the opponents side row.\n");}
        if ((turn==1&&coords[1]==0)||(turn==1&&coords[1]==23)){valid=0;printf("Invalid input, You cannot place a peg in the opponents side row.\n");}
        if (valid){
            int flag = doMove(board,coords,turn); 
            int win_status = flag; 
            if (win_status!=0&&turn==1){
                printBoard(board);
                win("Red");
                break; 
            }
            else if (win_status!=0&&turn==1){
                printBoard(board);
                win("Black");
                break; 
            }
            turn*=-1; 
            printBoard(board);

        }
        else{

        }

    }
}