# project2-team-5
##
## Running the program
### To compile the program: 
```
$ make
```
### To run tests: 
```
$ make debug
```

### To run the simulation:
```
$ ./schedulesim.exe <number of CPU-bound> <number of IO-bound> <number of Cycles>
```
The schedulesim takes in three command line arguments as input. It creates a simulation with the given number of CPU-bound processes, IO-bound processes, and the number of cycles. The schedulesim uses four different types of data structures to implement the simulation: roundrobin, which uses arraylist; fast roundrobin, which uses linkedlist; completely fair, which uses binary search tree; and fast completely fair, which uses red black tree. Final results can be seen in "cputimes.pdf"

## Assignment:
Christopher: ArrayList, Scheduler, Data, Removal for BST and RBT
<br />Liting: LinkedList, simulate, schedulesim, Insertion and find for BST and RBT 
