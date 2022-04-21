#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    // will allocate memory of int size to int pointer

    int *ptr = (int *)malloc(sizeof(int));

    *ptr = 7;

    cout << *ptr;
    return 0;
}