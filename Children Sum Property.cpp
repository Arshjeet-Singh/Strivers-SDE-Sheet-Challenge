#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    if(root==0)
    {
        return;
    }
    int rd=root->data,ld=0,rid=0;
    if(root->left)
    {
        ld=root->left->data;
    }
    if(root->right)
    {
        rid=root->right->data;
    }
    if(rd<=ld+rid)
    {
        root->data=ld+rid;
    }
    else if(rd>ld+rid)
    {
        if(root->left)
        {
            root->left->data=root->data;
        }
        if(root->right)
        {
            root->right->data=root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot=0;
    if(root->left)
    {
        tot+=root->left->data;
    }
    if(root->right)
    {
        tot+=root->right->data;
    }
    if(root->left || root->right)
    {
        root->data=tot;
    }
    // Write your code here.
}  
