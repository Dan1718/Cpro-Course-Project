Twixt

Game state will be stored by a 2D array of nodes. Each node can have the potential to be part of a linked list, but it is NOT necessary it has to be a linear linkedlist i.e each node can have multiple links. (it is also by default a doubly linked list. )

Each time a new node is placed, we check if that spot is taken, if not, we place the node. After that we check for possible link makings. If there are possible links, we check for barriers that might stop it. That's the interface 

To see if the game has ended or not, we start with all the nodes that are at the edges, traverse through them and see if we can reach that end. 

-- io.h io.c -- for printing the board
-- wincheck.h wincheck.c -- for checking the win condition 
-- logic.h logic.c -- validating pin position, making links, etc. -- will also define the node struct. 
-- 