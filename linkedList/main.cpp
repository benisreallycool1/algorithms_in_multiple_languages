/*
    A linked list is a linear data structure with a series of connected nodes.
    Each node stores the data and address of the next node.
    The address of the first node is HEAD. The last node will be NULL
    Linked lists can be of multiple types: singly, doubly, and circular linked list
    Each node consists of: data item, address of another node
    Therefore:
        struct node {
            int data;
            struct node *next;
        };
    Pseudo code of linked list with three items:
        Define all values - head, and one ... three all NULL
        allocate memory for one ... three with size node
        assign values for their date, Data: one->1, two->2, three->3
        Connect the nodes, Next: one->two, two->three, three->NULL
        save address of first node: head = one
    Pseudo code to add 4 between 1 and 2:
        Create new struct node and allocat memory
        Add data value as 4
        Make Next: four ->two, one->four
    In an array, must shift the positions
*/

#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *next;
};

int main()
{
    node *head;
    node *one = NULL;
    node *two = NULL;
    node *three = NULL;

    one = new node();
    two = new node();
    three = new node();

    one->value = 1;
    two->value = 2;
    three->value = 3;

    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;

    while (head != NULL)
    {
        cout << head->value;
        head = head->next;
    }
}