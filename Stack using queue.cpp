#include <bits/stdc++.h> 
class Stack {
    queue<int> q;
	// Define the data members.

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
        // Implement the getSize() function.
    }

    bool isEmpty() {
        return q.empty();
        // Implement the isEmpty() function.
    }

    void push(int element) {
        q.push(element);
        // Implement the push() function.
    }

    int pop() {
        if(q.size()==0)
        {
            return -1;
        }
        queue<int> q1;
        while(q.size()!=1)
        {
            q1.push(q.front());
            q.pop();
        }
        int ele=q.front();
        q.pop();
        q=q1;
        return ele;
        // Implement the pop() function.
    }

    int top() {
        if(q.size()==0)
        {
            return -1;
        }
        queue<int> q1;
        while(q.size()!=1)
        {
            q1.push(q.front());
            q.pop();
        }
        int ele=q.front();
        q.pop();
        q=q1;
        q.push(ele);
        return ele;
        // Implement the top() function.
    }
};
