/*
    A priority queue is a queue with each element having a priority value.
    Elements are served on the basis of their priority. Higher elements are served first.
    If elements with the same priority occur, they are served according to their order in the queue.

    Priority queue can be implemented using an array, linked list, heap data structure of binary search tree.
    Use heap data structure.
    See:
    Linked List:
        peek:O(1), insert: O(n), delete: O(1)
        binary heap: peek: O(1), insert: O(logn), delete: O(logn)
        binary search tree: " "
    Inserting element:
        Insert new element at the end of the tree.
        Heapify the tree

        if (No Node){
            create node
            }
        else {
            insert node at the end
            }
        heapify array

    Deleting element:
        Select element
        Swap with the last element
        Remove last element
        heapify the tree

        if node is last node{
            remove node
        } else {
            swap node with last node
            remove node
        }
        heapify array
*/

#include <iostream>
#include <vector>

using namespace std;

void swapfunc(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
// As an example -without pointers, this swaps values
void swap1(int a, int b)
{
    cout << a << b << endl;
    int temp = b;
    b = a;
    a = temp;
    cout << a << b;
}
void heapifyfunc(vector<int> &hT, int i)
{
    int size = hT.size();

    int largest = i;
    int l = 2 * i + 1; // Finds the left child
    int r = 2 * i + 2; // Finds the right child
    if (l < size && hT[l] > hT[largest])
    {
        largest = l;
    }
    if (r < size && hT[r] > hT[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swapfunc(&hT[i], &hT[largest]); // Set largest value
        heapifyfunc(hT, largest);       // Finally heapify
    }
}

void insertfunc(vector<int> &hT, int Num)
{
    int size = hT.size();
    if (size == 0)
    {
        hT.push_back(Num); // Adding element at the end of vector, doing line 18.
    }
    else
    {
        hT.push_back(Num);
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapifyfunc(hT, i);
        }
    }
}

void deleteNodefunc(vector<int> &hT, int numDel)
{
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (numDel == hT[i]) // Finds index of numDel
        {
            break;
        }
    }
    // Will now swap with last element
    swapfunc(&hT[i], &hT[size - 1]); // Last element ofc size-1
    hT.pop_back();                   // Remove it.
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapifyfunc(hT, i);
    }
}

void printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

int main()
{
    vector<int> heapTree;

    insertfunc(heapTree, 3);
    insertfunc(heapTree, 4);
    insertfunc(heapTree, 9);
    insertfunc(heapTree, 5);
    insertfunc(heapTree, 2);
    printArray(heapTree);
    deleteNodefunc(heapTree, 4);
    printArray(heapTree);
}
