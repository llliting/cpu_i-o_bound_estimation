
CC = g++
FLAGS = -Wall -O0 -std=c++11
DEBUG = --DDEBUG -g

all: process.o scheduler.o simulate.o schedulesim
debug: arraylist linkedlist roundrobin bstmultimap rbtmultimap bstnode completelyfair 

process.o: Process.cpp Process.hpp
		$(CC) $(FLAGS) -c Process.cpp

scheduler.o: Scheduler.cpp Scheduler.hpp 
		$(CC) $(FLAGS) -c Scheduler.cpp 

simulate.o: simulate.cpp simulate.hpp 
		$(CC) $(FLAGS) -c simulate.cpp  
	
schedulesim: schedulesim.cpp simulate.o Process.o Scheduler.o
		$(CC) $(FLAGS) -o schedulesim.exe schedulesim.cpp simulate.o Process.o Scheduler.o

bstnode: BSTNode_TEST.cpp BSTNode.hpp
		$(CC) $(FLAGS) -o BSTNode.exe BSTNode_TEST.cpp
		./BSTNode.exe

rbtnode: RBTNode_TEST.cpp RBTNode.hpp
		$(CC) $(FLAGS) -o RBTNode.exe RBTNode_TEST.cpp
		./RBTNode.exe

bstmultimap: BSTMultimap_TEST.cpp BSTMultimap.hpp BSTNode.hpp
		$(CC) $(FLAGS) -o BSTMultimap.exe BSTMultimap_TEST.cpp
		./BSTMultimap.exe

rbtmultimap: RBTMultimap_TEST.cpp RBTMultimap.hpp RBTNode.hpp
		$(CC) $(FLAGS) -o RBTMultimap.exe RBTMultimap_TEST.cpp
		./RBTMultimap.exe

arraylist: ArrayList_TEST.cpp ArrayList.hpp
		$(CC) $(FLAGS) -o ArrayList.exe ArrayList_TEST.cpp
		./ArrayList.exe

linkedlist: LinkedList_TEST.cpp LinkedList.hpp
		$(CC) $(FLAGS) -o LinkedList.exe LinkedList_TEST.cpp
		./LinkedList.exe

roundrobin: RoundRobin_TEST.cpp 
		$(CC) $(FLAGS) -o RoundRobin.exe RoundRobin_TEST.cpp
		./RoundRobin.exe

completelyfair: CompletelyFair_TEST.cpp 
		$(CC) $(FLAGS) -o CompletelyFair.exe CompletelyFair_TEST.cpp
		./CompletelyFair.exe

arraylist_cov: ArrayList_TEST.cpp ArrayList.hpp
		g++ --coverage ArrayList_TEST.cpp -o array.out
		./array.out
		gcov ArrayList_TEST.cpp
		gcov -f ArrayList_TEST.cpp
		gcov -b ArrayList_TEST.cpp
		lcov --directory . --zerocounters
		./array.out
		lcov --directory . --capture --output-file array.info
		genhtml array.info -o arraylist

linkedlist_cov: LinkedList_TEST.cpp LinkedList.hpp 
		g++ --coverage LinkedList_TEST.cpp -o linked.out
		./linked.out
		gcov LinkedList_TEST.cpp
		gcov -f LinkedList_TEST.cpp
		gcov -b LinkedList_TEST.cpp
		lcov --directory . --zerocounters
		./linked.out
		lcov --directory . --capture --output-file linked.info
		genhtml linked.info -o linkedList

roundrobin_cov: RoundRobin_TEST.cpp 
		g++ --coverage RoundRobin_TEST.cpp -o roundrobin.out
		./roundrobin.out
		gcov RoundRobin_TEST.cpp
		gcov -f RoundRobin_TEST.cpp
		gcov -b RoundRobin_TEST.cpp
		lcov --directory . --zerocounters
		./roundrobin.out
		lcov --directory . --capture --output-file roundrobin.info
		genhtml roundrobin.info -o roundrobin

bstnode_cov: BSTNode_TEST.cpp
		g++ --coverage BSTNode_TEST.cpp -o bstnode.out
		./bstnode.out
		gcov BSTNode_TEST.cpp
		gcov -f BSTNode_TEST.cpp
		gcov -b BSTNode_TEST.cpp
		lcov --directory . --zerocounters
		./bstnode.out
		lcov --directory . --capture --output-file bstnode.info
		genhtml bstnode.info -o bstnode

bstmultimap_cov: BSTMultimap_TEST.cpp
		g++ --coverage BSTMultimap_TEST.cpp -o bstmultimap.out
		./bstmultimap.out
		gcov BSTMultimap_TEST.cpp
		gcov -f BSTMultimap_TEST.cpp
		gcov -b BSTMultimap_TEST.cpp
		lcov --directory . --zerocounters
		./bstmultimap.out
		lcov --directory . --capture --output-file bstmultimap.info
		genhtml bstmultimap.info -o bstmultimap

rbtmultimap_cov: RBTMultimap_TEST.cpp
		g++ --coverage RBTMultimap_TEST.cpp -o rbtmultimap.out
		./rbtmultimap.out
		gcov RBTMultimap_TEST.cpp
		gcov -f RBTMultimap_TEST.cpp
		gcov -b RBTMultimap_TEST.cpp
		lcov --directory . --zerocounters
		./rbtmultimap.out
		lcov --directory . --capture --output-file rbtmultimap.info
		genhtml rbtmultimap.info -o rbtmultimap

clean:
		rm -f *.exe *.info *.out *.txt *.o *.gcno *.gcda *.gcov *.dot
		rm -f -r linkedList arraylist roundrobin bstnode bstmultimap rbtmultimap
