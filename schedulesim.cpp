#include <iostream>
#include "Scheduler.hpp"
#include "Process.hpp"
#include "simulate.hpp"
#include <iostream>
#include <string>

using namespace std;
int main(int argc, char* argv[]){
    if(argc != 4){
        cout << "wrong number of command line inputs" << endl;
        return 0;
    }

    long long numCPUProc = stoll(argv[1]);
    long long numIOProc = stoll(argv[2]);
    long long numCycles = stoll(argv[3]);

    RoundRobin* sched_rr = new RoundRobin(); 
    FastRoundRobin* sched_frr = new FastRoundRobin();
    CompletelyFair* sched_cf = new CompletelyFair();
    FastCompletelyFair* sched_fcc = new FastCompletelyFair();
    Scheduler* schedulesim[4] = {sched_rr, sched_frr, sched_cf, sched_fcc};
    string labels[4] = {"Round Robin Scheduler" , "Fast Round Robin Scheduler", "Completely Fair Scheduler", "Fast Completely Fair Scheduler"};


   


    for(int i = 0; i < 4; i ++){
        cout << "---------- Using " << labels[i] << " --------" << endl;
        double* stats = simulate(schedulesim[i], numCPUProc, numIOProc, numCycles);

        cout << "number of nanoseconds per scheduler use:   " << stats[0] << endl;
        cout << "average CPU time of all CPU-bound process: "<< stats[1] << endl;
        cout << "average wait time of all CPU-bound process: "<< stats[2] << endl;
        cout << "average CPU time of all IO-bound process: "<< stats[3] << endl;
        cout << "average wait time of all IO-bound process: "<< stats[4] << endl;
        cout << "\n" << endl;
        delete [] stats;
    }

    delete sched_rr;
    delete sched_frr;
    delete sched_cf;
    delete sched_fcc;
}