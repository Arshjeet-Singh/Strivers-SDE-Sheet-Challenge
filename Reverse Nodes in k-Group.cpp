#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node* help(Node *head, int n, int b[],int ind)
{
	if(head==0 || head->next==0)
	{
		return head;
	}
	if(ind<n-1 && b[ind]==0)
	{
		return help(head,n,b,ind+1);
	}
	int cnt=0;
	Node *prev=0,*curr=head,*nextnode;
	if(ind==n-1)
	{
		if(b[ind]==0)
		{
			return head;
		}
		while(curr!=0 && cnt< b[ind])
		{	
			nextnode=curr->next;
			curr->next=prev;
			prev=curr;
			curr=nextnode;
			cnt++;
		}
		head->next=nextnode;
		return prev;
	}
	else
	{
		while(curr!=0 && cnt< b[ind])
	{	
		nextnode=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextnode;
		cnt++;
	}
	head->next=help(nextnode,n,b,ind+1);
	return prev;
	}
	
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	return help(head,n,b,0);
	// Write your code here.
}
