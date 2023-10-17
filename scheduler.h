//
// Created by Abhlash Arnipalli on 10/16/23.
//
#ifndef HW__3_SCHEDULER_H
#define HW__3_SCHEDULER_H
#include <vector>
#include <queue>
#include <string>

struct Task {
    std::string name;
    int priority;
    int burst_time;
    int remaining_time;
};

void FCFS(std::vector<Task>& tasks);
void SJF(std::vector<Task>& tasks);
void PriorityScheduling(std::vector<Task>& tasks);
void RoundRobin(std::vector<Task>& tasks);
void PriorityRoundRobin(std::vector<Task>& tasks);



#endif //HW__3_SCHEDULER_H
