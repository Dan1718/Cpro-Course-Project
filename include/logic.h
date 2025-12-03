#ifndef LOGIC_H
#define LOGIC_H



typedef struct Node {
    int uid; 
    int x; 
    int y; 
    int colour; 
    struct Node* links[8]; 
    int state; 
}Node;



Node createNode(int x,int y,int uid);

int checkValid(Node board[24][24],int coords[2]); 
int doMove(Node board[][24],int coords[2],int player); 
#endif LOGIC_H