#include "Scheduler.hpp"
#include <iostream>
using namespace std;
RoundRobin::RoundRobin(){
    procQueue = new ArrayList<Process*> ();
}

RoundRobin::~RoundRobin(){
    delete procQueue;
}

void RoundRobin::addProcess(Process* proc){
    procQueue->pushBack(proc);
}

Process* RoundRobin::popNext(int curCycle){
    int size = procQueue->getSize();
    for(int i = 0; i < size; ++i){
        if((procQueue->getFront())->isBlocked(curCycle)){
            procQueue->pushBack(procQueue->getFront());
            procQueue->remove(0);
        }
        else{
            Process* temp = procQueue->getFront();
            procQueue->popFront();
            return temp;
        }
    }
    return 0;
}

FastRoundRobin::FastRoundRobin(){
    delete procQueue;
    procQueue = new LinkedList<Process*> ();
}

CompletelyFair::CompletelyFair(){
    procTree = new BSTMultimap<int, Process*>();
}
CompletelyFair::~CompletelyFair(){
    delete procTree;
}

void CompletelyFair::addProcess(Process* proc){
    procTree->insert(proc->getCPUTime(), proc);
}
Process* CompletelyFair::popNext(int curCycle){
    BSTForwardIterator<int, Process*> fi = procTree->getMin();
    while(fi.getValue()->isBlocked(curCycle)){
        fi.next();
        if(fi.isPastEnd())
            return 0;
    }
    Process* val = fi.getValue();
    procTree->remove(fi);
    return val;
}

FastCompletelyFair::FastCompletelyFair(){
    delete procTree;
    procTree = new RBTMultimap<int, Process*>();
}