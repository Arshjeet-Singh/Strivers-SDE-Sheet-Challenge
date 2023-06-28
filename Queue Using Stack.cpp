#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int> s;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        s.push(val);
        // Implement the enqueue() function.
    }
    int deQueue() {
        if(s.size()==0)
        {
            return -1;
        }
        stack<int> s1;
        while(s.size()!=1)
        {
            s1.push(s.top());
            s.pop();
        }
        int ele=s.top();
        s.pop();
        while(!s1.empty())
        {
            s.push(s1.top());
            s1.pop();
        }
        // s=s1;
        return ele;
        // Implement the dequeue() function.
    }

    int peek() {
        if(isEmpty())
        {
            return -1;
        }
        // if(s.size()==0)
        // {
        //     return -1;
        // }
        stack<int> s1=s;
        while(s.size()!=1)
        {
            // s1.push(s.top());
            s.pop();
        }
        int ele=s.top();
        s.pop();
        s=s1;
        return ele;
        // Implement the peek() function here.
    }

    bool isEmpty() {
        return s.size()==0;
        // Implement the isEmpty() function here.
    }
};
