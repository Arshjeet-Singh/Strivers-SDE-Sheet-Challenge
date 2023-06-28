#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int size;
    int fron;
    int rear;
public:
    Queue() 
    {
        size=100001;
        arr=new int[size];
        fron=rear=0;
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return fron==rear;
        // Implement the isEmpty() function
    }

    void enqueue(int data) {
        if(rear==size)
        {
            return;
        }
        arr[rear]=data;
        rear++;
        // Implement the enqueue() function
    }

    int dequeue() {
        if(fron==rear ||isEmpty())
        {
            return -1;
        }
        int ele=arr[fron];
        fron++;
        if(fron==rear)
        {
            fron=rear=0;
        }
        return ele;
        // Implement the dequeue() function
    }

    int front() {
        if(fron==rear)
        {
            return -1;
        }
        int ele=arr[fron];
        // front--;
        return ele;
        // Implement the front() function
    }
};
