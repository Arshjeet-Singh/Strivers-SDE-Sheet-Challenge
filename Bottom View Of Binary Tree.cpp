#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    if(root==0)
    {
        return ans;
    }    
    map<int,int> mp;
    queue<pair<BinaryTreeNode<int> *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        auto a=q.front();
        q.pop();
        BinaryTreeNode<int> * fnode=a.first;
        int hd=a.second;
        mp[hd]=fnode->data;
        if(fnode->left)
        {
          q.push({fnode->left, hd - 1});
        }
        if(fnode->right)
        {
          q.push({fnode->right, hd + 1});
        }
    }
    for(auto it:mp)
    {
        ans.push_back(it.second);
    }
    return ans;
    // Write your code here.
    
}
