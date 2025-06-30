// StackUndo.hpp
// ----------------------------------------------------
// Implementasi struktur data Stack manual untuk fitur Undo.
// Stack digunakan untuk menyimpan proses terakhir yang ditambahkan.
// Menyediakan fitur push (tambah), pop (hapus terakhir), dan isEmpty.
// ----------------------------------------------------

#ifndef STACK_UNDO_HPP
#define STACK_UNDO_HPP

#include "Process.hpp"

class StackUndo
{
private:
    Process stack[MAX];
    int top;

public:
    StackUndo()
    {
        top = -1;
    }

    void push(const Process &p)
    {
        if (top < MAX - 1)
        {
            stack[++top] = p;
        }
        else
        {
            cout << "Stack penuh! Tidak bisa undo lebih banyak." << endl;
        }
    }

    Process pop()
    {
        if (top >= 0)
        {
            return stack[top--];
        }
        else
        {
            cout << "Stack kosong!" << endl;
            return Process();
        }
    }

    bool isEmpty() const
    {
        return top == -1;
    }
};

#endif
