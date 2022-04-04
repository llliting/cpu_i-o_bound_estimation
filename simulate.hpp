#ifndef SIMULATE_HPP
#define SIMULATE_HPP

#include <chrono>
#include "Scheduler.hpp"
#include "Process.hpp"

double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles);

#endif