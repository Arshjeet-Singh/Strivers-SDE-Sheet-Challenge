#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
void ltra(TreeNode<int>* root,vector<int> &ans)
{
    if((root==0)||(root->left==0 && root->right==0))
    {
        return;
    }
    ans.push_back(root->data);
    if(root->left)
    {
        ltra(root->left,ans);
    }
    else
    {
        ltra(root->right,ans);
    }
} 
void btra(TreeNode<int>* root,vector<int> &ans)
{
    if(root==0)
    {
        return;
    }
    if(root->left==0 && root->right==0)
    {
        ans.push_back(root->data);
        // return;
    }
    btra(root->left,ans);
    btra(root->right,ans);
}
void rtra(TreeNode<int>* root,vector<int> &ans)
{
    if((root==0)||(root->left==0 && root->right==0))
    {
        return;
    }
    if(root->right)
    {
        rtra(root->right,ans);
    }
    else
    {
        rtra(root->left,ans);
    }
    ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root==0)
    {
        return ans;
    }
    ans.push_back(root->data);
    ltra(root->left,ans);
    btra(root->left,ans);
    btra(root->right,ans);
    rtra(root->right,ans);
    return ans;
    // Write your code here.
}
