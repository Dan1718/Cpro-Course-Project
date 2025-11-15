
#include <stdlib.h>
#include <stdio.h> 
#include "../include/logic.h"



Node createNode(int x,int y,int uid){
    Node new_node;
    new_node.uid =uid; 
    new_node.x = x; 
    new_node.colour=0; 
    new_node.y = y; 
    for (int i =0;8>i;i++){
        new_node.links[i]=0; 
    }
    return new_node; 
}

int checkValid(Node board[24][24],int coords[2]){
    int x = coords[0]; 
    int y = coords[1]; 
    if (x>24||x<0||y<0||y>24){
        printf("Invalid input, please enter coordinates within 0,0 and 24,24!! \n");
        return 0; 
    }
    else if (board[x][y].colour!=0){
        printf("The coordinate you are trying to place your peg at already has a peg!! \n");
        return 0; 
    }
    else{
        return 1; 
    }
}

void checkBarrier(Node board[24][24],int coords[2]){
    int flag =1; 
    
}
void doMove(Node board[24][24],int coords[2],int player){
    board[coords[0]][coords[1]].colour = player; 
}