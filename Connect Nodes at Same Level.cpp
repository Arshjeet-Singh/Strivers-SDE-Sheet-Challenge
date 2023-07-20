#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode< int > *> q;
    q.push(root);
    while(!q.empty())
    {
        int si=q.size();
        BinaryTreeNode< int > *prev;
        for(int i=0;i<si;i++)
        {
            BinaryTreeNode< int > * a=q.front();
            q.pop();
            if(i!=0)
            {
                prev->next=a;
            }
            prev=a;
            if(a->left)
            {
                q.push(a->left);
            }
            if(a->right)
            {
                q.push(a->right);
            }
        }
    }
    // Write your code here.
}
