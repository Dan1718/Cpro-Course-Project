
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
        new_node.links[i]=NULL; 
    }
    return new_node; 
}

int checkValid(Node board[24][24],int coords[2]){
    int x = coords[0]; 
    int y = coords[1]; 
    if (x>23||x<0||y<0||y>23){
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



int orientation(int *p, int *q, int *r){
    int val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    if (val==0){return 0; }
    return val>0 ? 1 : 2; 
}


int checkIntersect(int *c1, int *c2, int *c3, int *c4){
    int o1 = orientation(c1,   c2, c3);
    int o2 = orientation(c1, c2, c4);
    int o3 = orientation(c3, c4, c1);
    int o4 = orientation(c3, c4, c2);
    if (o1==0||o2==0||o3==0||o4==0) {return 0;}
    else if (o1!=o2&&o3!=o4){
        return 1; 
    }
    return 0; 
}

int linkInBounds(Node Board[24][24],int *center, int x,int y,int *indexes){ // TODO IMPLEMENT FUNCTION, also updates indexes with whatever indexes lie in bounds, others set it to -1. 
    int flag =0; 
    for (int i=0; 8>i; i++){
        Node* linkedNode = Board[x][y].links[i];
        if (linkedNode==NULL){
            indexes[i] = -1; 
            continue; 
        }
        else if ((abs(linkedNode->x-center[0])<=2)&&(abs(linkedNode->y-center[1])<=2)){
            indexes[i] = 0; 
            flag =1; 
        }
        else{
            indexes[i] = -1; 
        }
    }
    return flag; 
}
int linkPossible(Node board[24][24],int *c1,int *c2){
    if (board[c1[0]][c1[1]].colour!=board[c2[0]][c2[1]].colour){ return 0; }
    if ((abs(c1[0]-c2[0])==2&&abs(c1[1]-c2[1])==1)||(abs(c1[0]-c2[0])==1&&abs(c1[1]-c2[1])==2)){
        for (int i=-2; 2>=i; i++){
            for (int j=-2; 2>=j; j++){
                int indexes[8];
                if ((c1[0] + i) >= 0 && (c1[0] + i) < 24 && (c1[1] + j) >= 0 && (c1[1] + j) < 24){
                    if (linkInBounds(board, c1, c1[0]+i,c1[1]+j,indexes)){
                        for (int l = 0; 8>l; l++){
                            if (indexes[l]!=-1){
                                int c3[2] = {c1[0]+i,c1[1]+j};
                                int c4[2] = {board[c1[0]+i][c1[1]+j].links[l]->x,board[c1[0]+i][c1[1]+j].links[l]->y};
                                if (checkIntersect(c1, c2, c3, c4)){
                                    return 0; 
                                }
                            }
                        }
                    }
                }
                if ((c2[0] + i) >= 0 && (c2[0] + i) < 24 && (c2[1] + j) >= 0 && (c2[1] + j) < 24){
                    if (linkInBounds(board, c2, c2[0]+i,c2[1]+j,indexes)){
                        for (int l = 0; 8>l; l++){
                            if (indexes[l]!=-1){
                                int c3[2] = {c2[0]+i,c2[1]+j};
                                int c4[2] = {board[c2[0]+i][c2[1]+j].links[l]->x,board[c2[0]+i][c2[1]+j].links[l]->y};
                                if (checkIntersect(c1, c2, c3, c4)){
                                    return 0; 
                                }
                            }
                        }
                    }
                }
            }
        }
        return 1; 
    }
    else{return 0;}
}

void addLink(Node* node1, Node* node2){
    for (int i =0; 8>i;i++){
        if (node1->links[i]==NULL){
            node1->links[i]=node2;
        }
    }
}


void doMove(Node board[24][24],int coords[2],int player){
    board[coords[0]][coords[1]].colour = player; 
    for (int i=-2; 2>=i; i++){
        for (int j=-2; 2>=j; j++){
            int temp[2] = {coords[0]+i,coords[1]+j};
            if (temp[0]>=0&&temp[1]>=0&&temp[0]<24&&temp[1]<24){            
                int possible = linkPossible(board, coords, temp);
                if (possible){
                    addLink(&board[coords[0]][coords[1]], &board[temp[0]][temp[1]]);
                    addLink(&board[temp[0]][temp[1]], &board[coords[0]][coords[1]]);

                }
            }
        }
    }
}