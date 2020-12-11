#include "LinkedList.h"

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    LinkedList<int> lst;
    lst.push_front(1);
    lst.find(1);
    int val = lst.pop_front();
    cout << val;

    return 0;
}
