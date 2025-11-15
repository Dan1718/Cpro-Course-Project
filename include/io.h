#ifndef IO_H
#define IO_H

#include <stdio.h> 
#include <stdlib.h> 
#include "./logic.h"

// INPUT
void getTurn(char *colour,int *coords);

//OUTPUT
void printBoard(Node board[24][24]);
void askInput(char* colour); 
void win(char* colour); 



#endif IO_H
