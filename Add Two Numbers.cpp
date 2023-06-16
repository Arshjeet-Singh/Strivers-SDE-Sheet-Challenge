/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
Node *reverse(Node *head)
{
    if(head==0 || head->next==0)
    {
        return head;
    }
    Node *help=reverse(head->next);
    head->next->next=head;
    head->next=0;
    return help;
}
Node *addTwoNumbers(Node *num1, Node *num2)
{
    if(num1==0)
    {
        return num2;
    }
    if(num2==0)
    {
        return num1;
    }
    Node *p1=num1,*p2=num2;
    Node *dummy=new Node(-2);
    Node *help=dummy;
    int carry=0,sum=0;
    while(p1!=0 && p2!=0)
    {
        sum=p1->data+p2->data+carry;
        int digit=sum%10;
        carry=sum/10;
        Node *inode=new Node(digit);
        help->next=inode;
        help=help->next;
        p1=p1->next;
        p2=p2->next;
    }
    while(p1!=0)
    {
        sum=p1->data+carry;
        int digit=sum%10;
        carry=sum/10;
        Node *inode=new Node(digit);
        help->next=inode;
        help=help->next;
        p1=p1->next;
    }
    while(p2!=0)
    {
        sum=p2->data+carry;
        int digit=sum%10;
        carry=sum/10;
        Node *inode=new Node(digit);
        help->next=inode;
        help=help->next;
        p2=p2->next;
    }
    while(carry!=0)
    {
        sum=carry;
        int digit=sum%10;
        carry=sum/10;
        Node *inode=new Node(digit);
        help->next=inode;
        help=help->next;
    }
    return dummy->next;
    // Write your code here.
}
