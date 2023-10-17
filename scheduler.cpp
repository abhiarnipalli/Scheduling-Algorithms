//
// Created by Abhlash Arnipalli on 10/16/23.
//
#include "scheduler.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// FCFS Scheduling Algorithm
void FCFS(vector<Task>& tasks) {
    cout << "FCFS:" << endl;
    int currentTime = 0;

    for (Task& task : tasks) {
        cout << "Running task " << task.name << " for " << task.burst_time << " ms" << endl;
        currentTime += task.burst_time;
    }
}

// SJF Scheduling Algorithm
void SJF(vector<Task>& tasks) {
    cout << "Shortest-Job-First (SJF):" << endl;
    int currentTime = 0;

    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.burst_time < b.burst_time;
    });

    for (Task& task : tasks) {
        cout << "Running task " << task.name << " for " << task.burst_time << " ms" << endl;
        currentTime += task.burst_time;
    }
}

// Priority Scheduling Algorithm
void PriorityScheduling(vector<Task>& tasks) {
    cout << "Priority:" << endl;
    int currentTime = 0;

    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.priority > b.priority;
    });

    for (Task& task : tasks) {
        cout << "Running task " << task.name << " for " << task.burst_time << " ms" << endl;
        currentTime += task.burst_time;
    }
}

// Round-Robin Scheduling Algorithm
void RoundRobin(vector<Task>& tasks) {
    cout << "Round-Robin:" << endl;
    const int time_quantum = 10;
    int currentTime = 0;
    queue<Task> task_queue;

    for (Task& task : tasks) {
        task_queue.push(task);
    }

    while (!task_queue.empty()) {
        Task current_task = task_queue.front();
        task_queue.pop();

        cout << "Running task " << current_task.name << " for " << time_quantum << " ms" << endl;
        currentTime += time_quantum;
        current_task.remaining_time -= time_quantum;

        if (current_task.remaining_time > 0) {
            task_queue.push(current_task);
        }
    }
}

// Priority with Round-Robin Scheduling Algorithm
void PriorityRoundRobin(vector<Task>& tasks) {
    cout << "Priority with Round-Robin:" << endl;
    const int time_quantum = 10;
    int currentTime = 0;
    queue<Task> task_queue;

    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.priority > b.priority;
    });

    for (Task& task : tasks) {
        task_queue.push(task);
    }

    while (!task_queue.empty()) {
        Task current_task = task_queue.front();
        task_queue.pop();

        cout << "Running task " << current_task.name << " for " << time_quantum << " ms" << endl;
        currentTime += time_quantum;
        current_task.remaining_time -= time_quantum;

        if (current_task.remaining_time > 0) {
            task_queue.push(current_task);
        }
    }
}
