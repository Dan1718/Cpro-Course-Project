Twixt

Game state will be stored by a 2D array of nodes. Each node can have the potential to be part of a linked list, but it is NOT necessary it has to be a linear linkedlist i.e each node can have multiple links. (it is also by default a doubly linked list. )

Each time a new node is placed, we check if that spot is taken, if not, we place the node. After that we check for possible link makings. If there are possible links, we check for barriers that might stop it. That's the interface 

For checking if links can be made, the algorithm used is as follows. 
- You go through each node in a 3by3 cube centered on each node of the link, see if any have links made. And if they do, check if the other link is also in this 3by3. This is just a minor optimization. 
- For every link with it's link in the area made, you check if the two segments intersect using geometry. if yes no links, if no -- link made!. 

Win condition algorithm 

- Everynode will also have a state, while can be one of 5. The state represents what side rows (the final ones) it's connected to. 
```
0 - No side rows 
1 - left row
-1 - right row
2 - top row 
-2 - Bottom row
```
- Win condition is when a link is made, and the nodes on each side has complemented states. (one is connected to one row, and theo ther is the other. )
- When a node is placed on the side rows, it's given that state. Every other node starts with state 0 .
- everytime a new node is made, we have to update states, the algorithm for it is as follows. 
```
- Everytime a new node is made, and it only has one link that is to be made, the new node is assigned it's default state. 
- After that, we go through each of it's link, and non-zero states have priority, i.e we backtrack and go through every connected node and give it as 1/0 as needed. 
- If at any point of time complementing states are found == Win condition. Otherwise we just update the states. 
- This is optimal because you're never recalculating states. 
```

To see if the game has ended or not, we start with all the nodes that are at the edges, traverse through them and see if we can reach that end. 



-- io.h io.c -- for printing the board
-- wincheck.h wincheck.c -- for checking the win condition 
-- logic.h logic.c -- validating pin position, making links, etc. -- will also define the node struct. 
-- 



Phase 1 Contains board being printed, alternating moves, input validation. The constraint that red can't place a peg on the side has not been handled since it's more of game logic. You can place pegs, invalid input error messages, etc. Game quitting is also not implemented as of now. 
Daniel Vincent
2025117004

To run, 
```
make
./twixt
```