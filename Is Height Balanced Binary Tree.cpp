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
int height(BinaryTreeNode<int>* root)
{
    if(root==0)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
pair<bool,int> fast(BinaryTreeNode<int>* root)
{
    if(root==0)
    {
        return {true,0};
    }
    pair<bool,int> lan=fast(root->left);
    pair<bool,int> ran=fast(root->right);
    bool lans=lan.first;
    bool rans=ran.first;
    bool diff=abs(lan.second-ran.second)<=1;
    // bool diff=0;
    pair<bool,int> ans;
    ans.second=1+max(lan.second,ran.second);
    if(lans && rans && diff)
    {
        ans.first=true;
    }
    else
    {
        ans.first=0;
    }
    return ans;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    return fast(root).first;
    // if(root=0)
    // {
    //     return true;
    // }
    // bool lans=isBalancedBT(root->left);
    // bool rans=isBalancedBT(root->right);
    // bool diff=abs(height(root->left)-height(root->right))<=1;
    // // bool diff=0;
    // if(lans && rans && diff)
    // {
    //     return true;
    // }
    // else
    // {
    //     return 0;
    // }
    // Write your code here.
}
