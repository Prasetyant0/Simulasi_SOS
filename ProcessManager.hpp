// ProcessManager.hpp
// ----------------------------------------------------
// Menyimpan dan mengelola array proses secara manual (tanpa vector).
// Menyediakan fitur:
// - Menambahkan proses baru
// - Menampilkan semua proses
// - Sorting berdasarkan burst time atau prioritas
// - Pencarian proses berdasarkan ID atau nama
// - Menghapus proses berdasarkan ID
// ----------------------------------------------------

#ifndef PROCESS_MANAGER_HPP
#define PROCESS_MANAGER_HPP

#include "Process.hpp"

const int MAX = 100;

class ProcessManager
{
private:
    Process processes[MAX];
    int count;
    int idCounter;

public:
    // Konstruktor
    ProcessManager()
    {
        count = 0;
        idCounter = 1;
    }

    // Men-generate ID proses unik
    int generateId()
    {
        return idCounter++;
    }

    // Menambahkan proses baru ke array
    void addProcess(const Process &p)
    {
        if (count < MAX)
        {
            processes[count++] = p;
        }
        else
        {
            cout << "Kapasitas proses penuh!" << endl;
        }
    }

    // Menampilkan semua proses
    void showProcesses() const
    {
        if (count == 0)
        {
            cout << "Tidak ada proses yang tersimpan." << endl;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                processes[i].display();
            }
        }
    }

    // Sorting berdasarkan burst time (ascending)
    void sortByBurstTime()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (processes[j].burstTime > processes[j + 1].burstTime)
                {
                    swap(processes[j], processes[j + 1]);
                }
            }
        }
    }

    // Sorting berdasarkan prioritas (ascending)
    void sortByPriority()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (processes[j].priority > processes[j + 1].priority)
                {
                    swap(processes[j], processes[j + 1]);
                }
            }
        }
    }

    // Mencari proses berdasarkan ID (mengembalikan index atau -1)
    int searchById(int id) const
    {
        for (int i = 0; i < count; i++)
        {
            if (processes[i].id == id)
                return i;
        }
        return -1;
    }

    // Mencari proses berdasarkan nama (mengembalikan index atau -1)
    int searchByName(const string &name) const
    {
        for (int i = 0; i < count; i++)
        {
            if (processes[i].name == name)
                return i;
        }
        return -1;
    }

    // Menghapus proses berdasarkan ID
    void removeById(int id)
    {
        int index = searchById(id);
        if (index != -1)
        {
            for (int i = index; i < count - 1; i++)
            {
                processes[i] = processes[i + 1];
            }
            count--;
        }
        else
        {
            cout << "Proses dengan ID tersebut tidak ditemukan." << endl;
        }
    }

    // Mengambil seluruh array proses (untuk baca-tulis dari luar)
    Process *getProcesses()
    {
        return processes;
    }

    // Mengambil jumlah proses yang tersimpan
    int getCount() const
    {
        return count;
    }
};

#endif
