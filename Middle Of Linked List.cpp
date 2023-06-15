/*
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
*/
int cnt=0;
Node *findMiddle(Node *head) {
    if(head==0 || head->next==0)
    {
        return head;
    }
    Node *slow=head,*fast=head;
    while(fast!=0 && fast->next!=0)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    // Write your code here
}

