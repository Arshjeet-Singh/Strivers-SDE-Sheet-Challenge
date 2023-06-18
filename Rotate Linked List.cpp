/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
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
Node *rotate(Node *head, int k) {
      int l=len(head);
     k=k%l;
     if(head==0 || head->next==0 || k==0)
     {
          return head;
     }
    
     int r=l-k;
     int cnt=0;
     Node *t=head;
     while(t!=0 && cnt<r-1)
     {
          cnt++;
          t=t->next;
     }
     Node *nh=t->next,*temp;
     t->next=0;
     temp=nh;
     while(temp->next!=0)
     {
          temp=temp->next;
     }
     temp->next=head;
     return nh;
     // Write your code here.
}
