/*
    This extends the regular queue. The last element is connected to the first element.

    Enqueue:
        Check if queue is full.
        For first element => FRONT=0
        Increase REAR indec by 1.
        Add new element in position pointed to by REAR
    Dequeue:
        Check if queue is empty.
        Return FRONT return value.
        Increase FRONT by 1.
        For last element, set FRONT=REAR=-1

    Checking for full queue has cases:
        case 1: FRONT = 0 && REAR = SIZE-1
        case 2: FRONT = REAR + 1
*/

#include <iostream>
#define SIZE 5;

using namespace std;

class Queue
{
private:
    int items[SIZE], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        if (front == 0 && rear == SIZE - 1)
        {
            return true;
        }
        else if (front == rear + 1)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }
}