/*
    Dequeue (double ended queue). Has insertion and removal of elements at front or the rear.
    It does not follow FIFO
    Types of Deque
Input Restricted Deque
In this deque, input is restricted at a single end but allows deletion at both the ends.
Output Restricted Deque
In this deque, output is restricted at a single end but allows insertion at both the ends.
    Follow:
        Take array of size n.
        Have front = -1 and rear = 0
    Inserting at front:
        Check position at front
        if front <1 => front = n -1, which is the last index
        else front = front-1
        add new key into array[front]
    Insearting at rear:
        Check if array is full
        If it is => rear = 0
        else rear = rear + 1
        Add new key into array[rear]
    Delete from front:
        Check if queue is empty
        If it is, nothing happens
        else if front = rear (has one element) set front =-1, rear=-1
        else if front = n-1, front is at the end, set front = 0
        Else front  = front +1
    Delete from rear:
        Check if queue is empty
        if it is, nothing happens
        if front = rear, set front =-1 and rear = -1
        if rear = 0 (at the front), set rear = n -1
        else rear = rear-1
    Check empty function:
        if front  = -1:
            return true
        else:
            return false
    Check full function:
        if front = 0 && rear = n-1 or front = rear +1:
            return true
        else:
            return false
*/

#include <iostream>

using namespace std;

#define MAX 10

class Deque
{
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }
    void insertfront(int key);
    void insertrear(int key);
    void deletefront();
    void deleterear();
    bool isFull();
    bool isEmpty();
    int getFront();
    int getRear();
};

bool Deque::isFull()
{
    return ((front == 0 && rear == size - 1) || front == rear + 1);
}

bool Deque::isEmpty()
{
    return (front == -1);
}

void Deque::insertfront(int key)
{
    if (isFull())
    {
        cout << "Can't insert - queue is full\n"
             << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = size - 1;
    }
    else
    {
        front = front - 1;
    }
    arr[front] = key;
}

void Deque::insertrear(int key)
{
    if (isFull())
    {
        cout << "Cant insert - queue is full \n"
             << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == size - 1)
    {
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    arr[rear] = key;
}

void Deque::deletefront()
{
    if (isEmpty())
    {
        cout << "Queue is empty - can't delete\n"
             << endl;
        return;
    }

    if (front = rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }
}

void Deque::deleterear()
{
    if (isEmpty())
    {
        cout << "Queue is empty- can't delete\n"
             << endl;
        return;
    }

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = size - 1;
    }
    else
    {
        rear = rear - 1;
    }
}

int Deque::getFront()
{
    if (isEmpty())
    {
        cout << "Queue is empty -- can't get front\n"
             << endl;
        return (-1);
    }
    else
    {
        return arr[front];
    }
}

int Deque::getRear()
{
    if (isEmpty())
    {
        cout << "Queue is empty --cant get front\n"
             << endl;
        return (-1);
    }
    else
    {
        return arr[rear];
    }
}

int main()
{
    Deque dq(4);

    cout << "insert element at rear end \n";
    dq.insertrear(5);
    dq.insertrear(11);

    cout << "rear element: "
         << dq.getRear() << endl;

    dq.deleterear();
    cout << "after deletion of the rear element, the new rear element: " << dq.getRear() << endl;

    cout << "insert element at front end \n";

    dq.insertfront(8);

    cout << "front element: " << dq.getFront() << endl;

    dq.deletefront();

    cout << "after deletion of front element new front element: " << dq.getFront() << endl;
}