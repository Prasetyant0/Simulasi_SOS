// LinkedList.hpp
// ----------------------------------------------------
// Struktur data Linked List manual untuk menyimpan proses
// sebagai rantai node. Digunakan untuk fitur tambahan.
// ----------------------------------------------------
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "Process.hpp"

struct Node
{
    Process data;
    Node *next;

    Node(Process p) : data(p), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void append(Process p)
    {
        Node *newNode = new Node(p);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display()
    {
        cout << "\nData Proses dalam Linked List:\n";
        Node *temp = head;
        while (temp)
        {
            temp->data.display();
            temp = temp->next;
        }
    }

    void removeById(int id)
    {
        Node *current = head;
        Node *prev = nullptr;

        while (current)
        {
            if (current->data.id == id)
            {
                if (prev)
                {
                    prev->next = current->next;
                }
                else
                {
                    head = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    ~LinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif
