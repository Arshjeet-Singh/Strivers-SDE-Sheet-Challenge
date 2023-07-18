#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void bt(BinaryTreeNode<int>* root,BinaryTreeNode<int>* &prev,BinaryTreeNode<int>* &head)
{
    if(root==0)
    {
        return ;
    }
    bt(root->left,prev,head);
    if(prev==0)
    {
        head=root;
    }
    else
    {
        prev->right=root;
        root->left=prev;
    }
    prev=root;
    bt(root->right,prev,head);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* head=0,*prev=0;
    bt(root,prev,head);
    return head;
    // Write your code here
}
