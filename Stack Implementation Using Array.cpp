#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int *arr;
    int size;
    int op;
public:
    
    Stack(int capacity) {
       this->size=capacity;
       arr=new int[size];
       op=-1; 

        // Write your code here.
    }

    void push(int num) {
        if(op==size-1)
        {
            return;
        }
        op++;
        arr[op]=num;
        // Write your code here.
    }

    int pop() {
        if(op==-1)
        {
            return -1;
        }
        int ele=arr[op];
        op--;
        return ele;
        // Write your code here.
    }
    
    int top() {
        if(op==-1)
        {
            return -1;
        }
        int ele=arr[op];
        // top--;
        return ele;
        // Write your code here.
    }
    
    int isEmpty() {
        return op==-1;
        // Write your code here.
    }
    
    int isFull() {
        return op==size-1;
        // Write your code here.
    }
    
};
