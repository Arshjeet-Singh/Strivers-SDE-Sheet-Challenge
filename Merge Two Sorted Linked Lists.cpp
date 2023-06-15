#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==0)
    {
        return second;
    }
    if(second==0)
    {
        return first;
    }
    Node<int>* dummy=new Node<int>(-11);
    Node<int>* help=dummy;
    // cout<<dummy->data<<endl;
    Node<int>* p1=first,*p2=second;
    while(p1!=0 && p2!=0)
    {
        if(p1->data<=p2->data)
        {
            // if(dummy->next==0)
            // {
            //     dummy->next=p1;
            // }
             dummy->next=p1;
            p1=p1->next;
            dummy=dummy->next;
        }
        else
        {
            // if(dummy->next==0)
            // {
            //     dummy->next=p2;
            // }
            dummy->next=p2;
            p2=p2->next;
            dummy=dummy->next;
        }
    }
    while(p1!=0)
    {
        dummy->next=p1;
            p1=p1->next;
            dummy=dummy->next;
    }
    while(p2!=0)
    {
        dummy->next=p2;
            p2=p2->next;
            dummy=dummy->next;
    }
    return help->next;
    // Write your code here.
}
