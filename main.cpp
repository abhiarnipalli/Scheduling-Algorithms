#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "scheduler.h"
using namespace std;

int main() {
    ifstream input_file("schedule.txt");

    if (!input_file) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    vector<Task> tasks;
    string line;

    while (getline(input_file, line)) {
        string name;
        int priority, burst_time;
        char comma;
        istringstream ss(line);
        ss >> name >> comma >> priority >> comma >> burst_time;
        tasks.push_back({name, priority, burst_time, burst_time});
    }

    input_file.close();

    FCFS(tasks);
    cout << endl;
    SJF(tasks);
    cout << endl;
    PriorityScheduling(tasks);
    cout << endl;
    RoundRobin(tasks);
    cout << endl;
    PriorityRoundRobin(tasks);

    return 0;
}

