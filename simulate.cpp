
#include "simulate.hpp"
#include "ArrayList.hpp"
#include <chrono>

double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles){
    ArrayList<Process*>* procs = new ArrayList<Process*> (numCPUBound + numIOBound);

    for(long long i = 0; i < numIOBound; ++i){
        IOBoundProcess* proc = new IOBoundProcess(1);
        procs->pushBack(proc);
        sched->addProcess(proc);
    }
    
    for(long long i = 0; i < numCPUBound; ++i){
        CPUBoundProcess* proc = new CPUBoundProcess(0);
        procs->pushBack(proc);
        sched->addProcess(proc);
    }

    

    long long simCycles = 0;
    long long accum = 0;
    long long CPUtime = 0;
    long long CPUwait = 0;
    long long IOtime = 0;
    long long IOwait = 0;

    auto start = chrono::system_clock::now();
    while(simCycles <= numCycles){
        accum ++;
        Process* curr = sched->popNext(simCycles);
        if(curr == 0)
            simCycles += 10;
        else 
            simCycles += curr->useCPU(simCycles, 10);
        sched->addProcess(curr);

    }
    for(int i = 0; i < (numCPUBound + numIOBound); i++){
        Process* curr = procs->getItem(i);
        if(curr->getID() == 0){
            CPUwait += curr->getWaitTime(simCycles);
            CPUtime += curr->getCPUTime();
        }
        else{
            IOtime += curr->getCPUTime();
            IOwait += curr->getWaitTime(simCycles); 
        }      
    }


    auto end = chrono::system_clock::now();
    auto dur = end - start;
    auto durNS = chrono::duration_cast<chrono::nanoseconds>(dur);
    double elapsed = (double)durNS.count();

    double* result = new double[5];
    result[0] = elapsed/accum;
    result[1] = CPUtime/numCPUBound;
    result[2] = CPUwait/numCPUBound;
    result[3] = IOtime/numIOBound;
    result[4] = IOwait/numIOBound;

    for(int i = 0; i < (numCPUBound + numIOBound); i++)
        delete procs->getItem(i);
    delete procs;
    return result;

}