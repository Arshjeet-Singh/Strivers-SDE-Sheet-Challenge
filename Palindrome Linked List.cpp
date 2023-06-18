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
LinkedListNode<int> *mid(LinkedListNode<int> *head)
{
    if(head==0 || head->next==0)
    {
        return head;
    }
    LinkedListNode<int> *slow=head,*fast=head->next;
    while(fast!=0 && fast->next!=0)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
LinkedListNode<int> *reverse(LinkedListNode<int>*head)
{
    if(head==0 || head->next==0)
    {
        return head;
    }
    LinkedListNode<int>*help=reverse(head->next);
    head->next->next=head;
    head->next=0;
    return help;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(head==0 || head->next==0)
    {
        return true;
    }
    LinkedListNode<int> *m=mid(head);
    LinkedListNode<int> * mn=m->next;
    m->next=0;
    LinkedListNode<int> *p1=head,*p2=reverse(mn);
    while(p1!=0 && p2!=0)
    {
        if(p1->data!=p2->data)
        {
            return false;
            break;
        }
        p1=p1->next;
        p2=p2->next;
    }
    return true;
    // Write your code here.

}
