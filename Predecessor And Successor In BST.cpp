#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int,int> ans;
    if(root==0)
    {
        return {-1,-1};
    }
    BinaryTreeNode<int>* node=root;
    int prev=-1,succ=-1;
    while(node !=0 && node->data!=key)
    {
        if(node->data>key)
        {
            succ=node->data;
            node=node->left;
        }
        else
        {
            prev=node->data;
            node=node->right;
        }
    }
    BinaryTreeNode<int>* l=node->left,*r=node->right;

    while(l!=0)
    {
        prev=l->data;
        l=l->right;
    }
    int agla=succ;
    while(r!=0)
    {
        agla=r->data;
        r=r->left;
    }
    ans.first=prev;
    ans.second=agla;
    return ans;
    // Write your code here.
}
