#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if(root==0)
    {
        return 0;
    }
    if(root==P || root==Q)
    {
        return root;
    }
    if(root->data>P->data && root->data>Q->data)
    {
        return LCAinaBST(root->left,P,Q);
    }
    if(root->data<P->data && root->data<Q->data)
    {
        return LCAinaBST(root->right,P,Q);
    }
    return root;
    // TreeNode<int>* lans=LCAinaBST(root->left, P, Q);
    // TreeNode<int>* rans=LCAinaBST(root->right, P, Q);
    // if(lans!=0 && rans!=0)
    // {
    //     return root;
    // }
    // if(lans!=0 && rans==0)
    // {
    //     return lans;
    // }
    // if(lans==0 && rans!=0)
    // {
    //     return rans;
    // }
    // if(lans==0 && rans==0)
    // {
    //     return 0;
    // }
	// Write your code here
}
