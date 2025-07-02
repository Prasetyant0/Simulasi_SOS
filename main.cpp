// main.cpp
// ------------------------------------------------------------------
// Program utama Mini-SOS Simulator.
// Menyediakan menu interaktif untuk pengguna:
// - Menambah proses
// - Menampilkan proses
// - Mengurutkan proses (burst/prioritas)
// - Mencari proses (berdasarkan ID/nama)
// - Simulasi eksekusi proses (FIFO)
// - Undo proses terakhir (Stack manual)
// - Tampilkan proses dalam Linked List dan Tree
// - Hapus proses berdasarkan ID
// ------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

#include "Process.hpp"
#include "ProcessManager.hpp"
#include "StackUndo.hpp"
#include "QueueSimulator.hpp"
#include "LinkedList.hpp"
#include "TreeHirarki.hpp"

using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForUser()
{
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void tampilkanMenu()
{
    cout << "\n=== MINI OS SIMULATOR ===\n";
    cout << "1. Tambah Proses\n";
    cout << "2. Tampilkan Semua Proses\n";
    cout << "3. Urutkan Proses\n";
    cout << "4. Cari Proses\n";
    cout << "5. Simulasi Eksekusi (Queue FIFO)\n";
    cout << "6. Undo Tambah Proses Terakhir\n";
    cout << "7. Tampilkan Linked List Proses\n";
    cout << "8. Tampilkan Hirarki Tree Proses\n";
    cout << "9. Hapus Proses by ID\n";
    cout << "0. Keluar\n";
    cout << "Pilih: ";
}

int main()
{
    ProcessManager manager;
    StackUndo undoStack;
    QueueSimulator queueSim;
    LinkedList listProses;
    TreeNode *rootTree = nullptr;

    int pilihan;

    do
    {
        clearScreen();
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
        {
            string name;
            int burst, priority, parentId = -1;

            cout << "Nama Proses: ";
            getline(cin, name);
            cout << "Burst Time: ";
            while (!(cin >> burst)) {
                cout << "Input harus berupa angka! Masukkan ulang Burst Time: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Prioritas: ";
            while (!(cin >> priority)) {
                cout << "Input harus berupa angka! Masukkan ulang Prioritas: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            if (rootTree != nullptr)
            {
                cout << "ID Parent (masukkan -1 untuk root): ";
                while (!(cin >> parentId)) {
                    cout << "Input harus berupa angka! Masukkan ulang ID Parent: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore();
            }

            Process p(manager.generateId(), name, burst, priority);
            manager.addProcess(p);
            undoStack.push(p);
            queueSim.enqueue(p);
            listProses.append(p);

            TreeNode *newNode = new TreeNode(p);
            if (!rootTree || parentId == -1)
            {
                if (!rootTree)
                    rootTree = newNode;
                else
                    rootTree->addChild(newNode);
            }
            else
            {
                TreeNode *parent = rootTree->findNode(parentId);
                if (parent)
                    parent->addChild(newNode);
                else
                    cout << "Parent ID tidak ditemukan. Ditambahkan ke root.\n";
            }

            cout << "Proses berhasil ditambahkan.\n";
            waitForUser();
            break;
        }

        case 2:
            manager.showProcesses();
            waitForUser();
            break;

        case 3:
        {
            int mode;
            cout << "1. Berdasarkan Prioritas\n";
            cout << "2. Berdasarkan Burst Time\n";
            cout << "Pilih: ";
            cin >> mode;
            if (mode == 1)
                manager.sortByPriority();
            else
                manager.sortByBurstTime();
            cout << "Proses berhasil diurutkan.\n";
            waitForUser();
            break;
        }

        case 4:
        {
            int mode;
            cout << "1. Cari berdasarkan ID\n";
            cout << "2. Cari berdasarkan Nama\n";
            cout << "Pilih: ";
            cin >> mode;

            if (mode == 1)
            {
                int id;
                cout << "ID Proses: ";
                cin >> id;
                int idx = manager.searchById(id);
                if (idx != -1)
                    manager.getProcesses()[idx].display();
                else
                    cout << "Proses tidak ditemukan.\n";
            }
            else
            {
                string name;
                cin.ignore();
                cout << "Nama Proses: ";
                getline(cin, name);
                int idx = manager.searchByName(name);
                if (idx != -1)
                    manager.getProcesses()[idx].display();
                else
                    cout << "Proses tidak ditemukan.\n";
            }
            waitForUser();
            break;
        }

        case 5:
            queueSim.simulateExecution();
            waitForUser();
            break;

        case 6:
            if (!undoStack.isEmpty())
            {
                Process last = undoStack.pop();
                manager.removeById(last.id);
                queueSim.removeById(last.id);
                listProses.removeById(last.id);
                if (rootTree)
                    rootTree->removeById(last.id);
                cout << "Undo berhasil: Proses '" << last.name << "' dihapus dari semua struktur data.\n";
            }
            else
            {
                cout << "Stack undo kosong.\n";
            }
            waitForUser();
            break;

        case 7:
            listProses.display();
            waitForUser();
            break;

        case 8:
            if (rootTree)
            {
                cout << "\nStruktur Hirarki Proses (Tree):\n";
                rootTree->printTree();
            }
            else
            {
                cout << "Tree kosong.\n";
            }
            waitForUser();
            break;

            case 9:
            {
                int id;
                cout << "Masukkan ID Proses yang ingin dihapus: ";
                while (!(cin >> id))
                {
                    cout << "Input tidak valid. Masukkan ID Proses: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                manager.removeById(id);
                queueSim.removeById(id);
                undoStack.removeById(id);
                listProses.removeById(id);
                if (rootTree) rootTree->removeById(id);
                cout << "Proses dengan ID " << id << " berhasil dihapus.\n";
                waitForUser();
                break;
            }

        case 0:
            cout << "Program selesai. Terima kasih!\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
            waitForUser();
            break;
        }

    } while (pilihan != 0);

    delete rootTree;
    return 0;
}
