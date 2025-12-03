#include <stdio.h> 
#include <stdlib.h> 
#include "../include/logic.h"
void printBoard(Node board[24][24]){
    char Red = 'X'; 
    char Black = '#'; 
    printf("   ");
    for (int i =0; 24>i;i++){
        printf("%2d ",i);
        if (i==0||i==22){
            printf("  ");
        }
    }
    printf("\n");
    for (int x=0;24>x;x++){
        printf("%2d ",x);
        for (int y=0; 24>y;y++){
            
            Node node = board[x][y];
            if (node.colour==0){printf(" . ");}
            else if (node.colour==1){printf(" %c ",Red);}
            else if (node.colour==-1){printf(" %c ",Black);}
            //else {printf(" %d ",node.colour);}
            if (y==0||y==22){printf(" | ");}
            
        }
        printf("\n");
        if (x==0||x==22){
            for (int y= 0; 80>y;y++){
                printf("-");
            }

            printf("\n");
        }

    }
    printf("\n");
}


void getTurn(char* colour, int* coords){
    for (int i=0;80>i;i++){
        printf("-");
    }
    printf("\n");
    printf("Enter your choice %s player : ",colour); 
    if (scanf("%d %d",coords,coords+1)!=2){
        printf("Invalid input!"); 
        coords[0]=50;
        coords[1]=50;
        while (getchar()!='\n');
    } 
    printf("\n Validating input... \n");
}

void win(char* colour){
    printf("\n");
    for (int i=0;80>i;i++){
        printf("-");
    }
    printf("%s WON!!!\n",colour);
}

