#include <bits/stdc++.h>
using namespace std;

class Queue
{
    // Define the data members(if any) here.
    stack<int> input, output;
    int size;

public:
    Queue()
    {
        // Initialize your data structure here.
        size = 0;
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        while (!input.empty())
        {
            int temp = input.top();
            output.push(temp);
            input.pop();
        }
        input.push(val);
        while (!output.empty())
        {
            int temp = output.top();
            input.push(temp);
            output.pop();
        }
        size++;
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        if (input.empty())
            return -1;
        else
        {
            int temp = input.top();
            input.pop();
            size--;
            return temp;
        }
    }

    int peek()
    {
        // Implement the peek() function here.
        if (input.empty())
            return -1;
        else
        {
            int temp = input.top();
            return temp;
        }
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        return input.empty();
    }
};