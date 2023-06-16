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
int len(Node* head)
{
    if(head==0)
    {
        return 0;
    }
    Node *temp=head;
    int cnt=0;
    while(temp!=0)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
Node* removeKthNode(Node* head, int K)
{
    int l=len(head);
    int rl=l-K;
    Node *temp=head,*prev;
    int cnt=0;
    if(rl==0)
    {
        head=head->next;
        return head;
    }
    while(cnt<rl && temp!=0)
    {
        cnt++;
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
    return head;
    // Write your code here.
}
