// TreeHierarchy.hpp
// ----------------------------------------------------
// Struktur data Tree manual untuk menyimpan proses
// dalam bentuk parent-child. Digunakan untuk fitur tambahan.
// ----------------------------------------------------
#ifndef TREE_HIERARCHY_HPP
#define TREE_HIERARCHY_HPP

#include "Process.hpp"

struct TreeNode
{
    Process data;
    TreeNode *firstChild;
    TreeNode *nextSibling;

    TreeNode(Process p) : data(p), firstChild(nullptr), nextSibling(nullptr) {}

    // Menambahkan child ke node ini
    void addChild(TreeNode *child)
    {
        if (!firstChild)
        {
            firstChild = child;
        }
        else
        {
            TreeNode *temp = firstChild;
            while (temp->nextSibling)
                temp = temp->nextSibling;
            temp->nextSibling = child;
        }
    }

    // Mencetak tree secara visual
    void printTree(int depth = 0)
    {
        for (int i = 0; i < depth; ++i)
            cout << "  ";
        cout << "↳ ";
        data.display();

        if (firstChild)
            firstChild->printTree(depth + 1);
        if (nextSibling)
            nextSibling->printTree(depth);
    }

    // Mencari node berdasarkan ID proses
    TreeNode *findNode(int id)
    {
        if (data.id == id)
            return this;
        if (firstChild)
        {
            TreeNode *found = firstChild->findNode(id);
            if (found)
                return found;
        }
        if (nextSibling)
        {
            TreeNode *found = nextSibling->findNode(id);
            if (found)
                return found;
        }
        return nullptr;
    }

    bool removeById(int id)
    {
        if (data.id == id)
        {
            return true;
        }

        TreeNode *prev = nullptr;
        TreeNode *current = firstChild;

        while (current)
        {
            if (current->data.id == id)
            {
                if (prev)
                {
                    prev->nextSibling = current->nextSibling;
                }
                else
                {
                    firstChild = current->nextSibling;
                }
                delete current;
                return true;
            }

            if (current->removeById(id))
            {
                return true;
            }

            prev = current;
            current = current->nextSibling;
        }
        return false;
    }
};

#endif
