/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node *merge(Node *p1,Node *head)
{
	Node *dummy=new Node(-11);
	Node *help=dummy;
	Node *t1=p1,*t2=head;
	while(t1!=0 && t2!=0)
	{
		if(t1->data<=t2->data)
		{
			help->child=t1;
			t1=t1->child;
			help=help->child;
		}
		else
		{
			help->child=t2;
			t2=t2->child;
			help=help->child;
		}
	}
	while(t1!=0)
	{
		help->child=t1;
			t1=t1->child;
			help=help->child;
	}
	while(t2!=0)
	{
		help->child=t2;
		t2=t2->child;
		help=help->child;
	}
	return dummy->child;
}
Node* flattenLinkedList(Node* head) 
{
	if(head==0 || head->next==0)
	{
		return head;
	}
	Node *p1;
	Node *p2=head->next;
	head->next=0;
	p1=flattenLinkedList(p2);
	return merge(p1,head);
	// Write your code here
}
