/****************************************************************
    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };
*****************************************************************/
#include<bits/stdc++.h>
Node *firstNode(Node *head)
{
    Node *s=head,*f=head;
    while(f!=0 && f->next!=0)
    {
        s=s->next;
        f=f->next->next;
        if(s==f)
        {
            break;
        }
    }
    if(f==0 || f->next==0)
    {
        return 0;
    }
    Node *ep=head;
    while(ep!=s)
    {
        ep=ep->next;
        s=s->next;
    }
    return ep;
    // unordered_set<Node *> s;
    // Node*temp=head;
    // while(temp!=0)
    // {
    //     if(s.find(temp)!=s.end())
    //     {
    //         return temp;
    //     }
    //     s.insert(temp);
    //     temp=temp->next;
    // }
    // return 0;
    //    Write your code here.
}
