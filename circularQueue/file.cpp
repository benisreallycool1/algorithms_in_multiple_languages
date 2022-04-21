// Circular Queue implementation in C++

#include <iostream>
#define SIZE 5 /* Size of Circular Queue */

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
    // Check if the queue is full
    bool isFull()
    {
        if (front == 0 && rear == SIZE - 1)
        {
            return true;
        }
        if (front == rear + 1)
        {
            return true;
        }
        return false;
    }
    // Check if the queue is empty
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    void enQueue(int element)
    {
        if (isFull())
        {
            cout << "Cant add element, queue is full"
                 << "\n";
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            };
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << endl
                 << "Inserted " << element << endl;
        }
    }
    int deQueue()
    {
        int element;
        if (isEmpty())
        {
            cout << "Queue is empty"
                 << "\n";
            return (-1);
        }
        else
        {
            element = items[front];
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % SIZE;
            }
            cout << element << "\n";
            return (element);
        }
    }

    void display()
    {
        // Function to display status of Circular Queue
        int i;
        if (isEmpty())
        {
            cout << endl
                 << "Empty Queue" << endl;
        }
        else
        {
            cout << "Front -> " << front;
            cout << endl
                 << "Items -> ";
            for (i = front; i != rear; i = (i + 1) % SIZE)
                cout << items[i];
            cout << items[i];
            cout << endl
                 << "Rear -> " << rear;
        }
    }
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.display();
    q.deQueue();
    q.display();
    int elem = q.deQueue();
    if (elem != -1)
    {
        cout << endl
             << "Deleted: " << elem << endl;
    }
    q.display();
}