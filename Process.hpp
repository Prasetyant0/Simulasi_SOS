// Process.hpp
// ---------------------------------------------
// Berisi definisi struct Process.
// Menyimpan info proses: id, nama, burst time, prioritas, dan status.
// Menyediakan fungsi display() untuk mencetak informasi proses.
// ---------------------------------------------

#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <iostream>
#include <string>
using namespace std;

struct Process
{
    int id;
    string name;
    int burstTime;
    int priority;
    string status; // "Ready", "Running", "Finished"

    // Constructor default dengan parameter
    Process(int _id = 0, string _name = "", int _burstTime = 0, int _priority = 0)
        : id(_id), name(_name), burstTime(_burstTime), priority(_priority), status("Ready") {}

    // Menampilkan detail proses
    void display() const
    {
        cout << "[ID: " << id << "] "
             << name << " | Burst: " << burstTime
             << " | Priority: " << priority
             << " | Status: " << status << endl;
    }
};

#endif
