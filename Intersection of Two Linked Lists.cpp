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
int len(Node *head)
{
    Node *temp=head;
    int cnt=0;
    while(temp!=0)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    if(firstHead==0 || secondHead==0)
    {
        return 0;
    }
    int l1=len(firstHead),l2=len(secondHead);
    Node *p1=firstHead,*p2=secondHead;
    if(l1>=l2)
    {
        int diff=l1-l2;
        while(p1!=0 && diff>0)
        {
            p1=p1->next;
            diff--;
        }    
    }
    else
    {
        int diff=l2-l1;
        while(p2!=0 && diff>0)
        {
            p2=p2->next;
            diff--;
        }
    }
    while(p1!=0 && p2!=0 && p1!=p2)
    {
        p1=p1->next;
        p2=p2->next;
    }
    return p1;
    //Write your code here
}
