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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==0 || head->next==0)
    {
        return head;
    }
    LinkedListNode<int>* help=reverseLinkedList(head->next);
    head->next->next=head;
    head->next=0;
    return help;
    // Write your code here
}
