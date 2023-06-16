#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
    LinkedListNode<int> * p1=node,*p2=node->next,*prev;
    while(p1->next!=0)
    {
        p1->data=p2->data;
        prev=p1;
        p1=p1->next;
        p2=p2->next;
    }
    prev->next=0;
    delete p1;
    
    // Write your code here.
}
