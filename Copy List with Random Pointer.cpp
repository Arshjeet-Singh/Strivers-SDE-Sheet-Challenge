#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
void inserttail(LinkedListNode<int> *&head,LinkedListNode<int> *&tail,int d)
{
    LinkedListNode<int> *newnode=new LinkedListNode<int>(d);
    if(head==0)
    {
        head=tail=newnode;
        return;
    }
    tail->next=newnode;
    tail=newnode;
}
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *clonehead=0,*clonetail=0;
    LinkedListNode<int> *temp=head;
    unordered_map<LinkedListNode<int> *,LinkedListNode<int> *> mp;
    while(temp!=0)
    {
        inserttail(clonehead,clonetail,temp->data);
        mp[temp]=clonetail;
        temp=temp->next;
    }
    temp=head;
    LinkedListNode<int> *ctemp=clonehead;
    while(temp!=0)
    {
        ctemp->random=mp[temp->random];
        ctemp=ctemp->next;
        temp=temp->next;
    }
    return clonehead;

    // Write your code here.
}
