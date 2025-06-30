// QueueSimulator.hpp
// ----------------------------------------------------
// Implementasi struktur data Queue manual (circular queue).
// Digunakan untuk mensimulasikan eksekusi proses secara FIFO.
// Menyediakan fungsi enqueue (tambahkan ke antrian),
// dan simulateExecution (menjalankan proses satu per satu).
// ----------------------------------------------------

#ifndef QUEUE_SIMULATOR_HPP
#define QUEUE_SIMULATOR_HPP

#include "Process.hpp"

class QueueSimulator
{
private:
    Process queue[MAX];
    int front;
    int rear;
    int size;

public:
    QueueSimulator()
    {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(const Process &p)
    {
        if (size >= MAX)
        {
            cout << "Antrian penuh! Tidak dapat menambahkan proses." << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = p;
        size++;
    }

    Process dequeue()
    {
        if (size <= 0)
        {
            cout << "Antrian kosong!" << endl;
            return Process();
        }
        Process p = queue[front];
        front = (front + 1) % MAX;
        size--;
        return p;
    }

    void simulateExecution()
    {
        if (size == 0)
        {
            cout << "Tidak ada proses dalam antrian." << endl;
            return;
        }

        cout << "\\nSimulasi Eksekusi Proses:" << endl;
        while (size > 0)
        {
            Process p = dequeue();
            p.status = "Running";
            p.display();
            p.status = "Finished";
            cout << "--> Selesai Eksekusi" << endl;
        }
    }
};

#endif
