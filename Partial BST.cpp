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
class info
{
    public:
    int maxi;
    int mini;
    bool isbst; 
};
info fast(BinaryTreeNode<int> *root){
    if(root==0)
    {
        return {INT_MIN,INT_MAX,true};
    }
    info lans=fast(root->left);
    info rans=fast(root->right);
    info ans;
    // if(rans.maxi>root->data)
    // {
    //     ans.maxi=rans.maxi;
    // }
    // else
    // {
    //     ans.maxi=root->data;
    // }
    // if(lans.mini<root->data)
    // {
    //     ans.mini=lans.mini;
    // }
    // else
    // {
    //     ans.mini=root->data;
    // }
    ans.maxi=max(rans.maxi,root->data);
    ans.mini=min(lans.mini,root->data);
    if(lans.isbst && rans.isbst && (root->data>lans.maxi && root->data<rans.mini))
    {
        ans.isbst=true;
    }
    else
    {
        ans.isbst=false;
    }
    return ans;
}
bool koshish(BinaryTreeNode<int> *root,long mini,long maxi)
{
    if(root==0 )
    {
        return true;
    }
    if(root->data>maxi || root->data<mini)
    {
        return false;
    } 
    // bool lans=koshish(root->left, mini, root->data);
    // bool rans=koshish(root->right, root->data, maxi);
    return koshish(root->left, mini, root->data)&&koshish(root->right, root->data, maxi);
    // if(root->data>mini && root->data<maxi && lans && rans)
    // {
    //     return true;
    // }
    // return false;
}
bool validateBST(BinaryTreeNode<int> *root) {
    // return fast(root).isbst;
    return koshish(root, LONG_MIN, LONG_MAX);
    // Write your code here
}
