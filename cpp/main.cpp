/*
    A stack is a linear data structure that follows Last In First Out
    (LIFO). Putting an item on top of the stack is push and removing is pop.

*/

/*
    How the algorithm works:
    A pointer "TOP" keeps track of the top element of the stack
    Initializing the stack, set TOP=-1. See if the stack is empty
    by TOP==-1
    Pushing an element will increase TOP, popping an element, return
    element pointed to by TOP and reduce its value.
    Before pushing, check if stack is full.
    Before popping, check if stack is empty
*/
/*
    Takes constant time O(1)
*/

#include <stdlib.h>
#include <iostream>

using namespace std;

int Coolsize = 0; // Max 10
#define MAX 10    // This is defining MAX to be 10
// Create stack
struct stack
{
    int items[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s)
{
    s->top = -1;
    //-> is used, because to access members of a structure use dot op, however, through a pointer use ->
}

// checking if stack is full
int isfull(st *s)
{
    if (s->top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// checking if stack is empty

int isempty(st *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Add element to stack

void push(st *s, int newitem)
{
    if (isfull(s))
    {
        cout << "stack is full, can't add to it";
    }
    else
    {
        s->top++;
        s->items[s->top] = newitem;
    }
    Coolsize++;
}

// remove items
void pop(st *s)
{
    if (isempty(s))
    {
        cout << "\n stack is empty \n";
    }
    else
    {
        cout << "Item popped = " << s->items[s->top];
        s->top--;
    }
    Coolsize--;
    cout << endl;
}

// print elements

void printStack(st *s)
{
    printf("Stack: ");
    for (int i = 0; i < Coolsize; i++)
    {
        cout << s->items[i] << " ";
    }
    cout << endl;
}

// driver

int main()
{
    int ch;
    st *s = (st *)malloc(sizeof(st));
    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);

    printStack(s);

    pop(s);
    pop(s);
    pop(s);

    cout << "\nAfter popping out\n";
    printStack(s);
}