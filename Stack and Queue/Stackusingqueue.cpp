#include <bits/stdc++.h>
using namespace std;
class Stack
{
    // Define the data members.

private:
    queue<int> q1;
    queue<int> q2;
    int length;

public:
    Stack()
    {
        // Implement the Constructor.
        length = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return length;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return length == 0;
    }

    void push(int element)
    {
        // Implement the push() function.
        q2.push(element);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        length++;
    }

    int pop()
    {
        // Implement the pop() function.
        if (!q1.empty())
        {
            int value = q1.front();
            q1.pop();
            length--;
            return value;
        }
        return -1;
    }

    int top()
    {
        // Implement the top() function.
        if (!q1.empty())
            return q1.front();
        return -1;
    }
};