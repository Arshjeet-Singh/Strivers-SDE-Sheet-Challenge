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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root==0)
    {
        return ans;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    int k=0;
    while(!q.empty())
    {
        int si=q.size();
        vector<int> v;
        for(int i=0;i<si;i++)
        {
            auto a=q.front();
            q.pop();
            if(a->left)
            {
                q.push(a->left);
            }
            if(a->right)
            {
                q.push(a->right);
            }
            v.push_back(a->data);
        }
        if(k%2==0)
        {
            for(int i=0;i<v.size();i++)
            {
                ans.push_back(v[i]);
            }
        }
        else
        {
            for(int i=v.size()-1;i>=0;i--)
            {
                ans.push_back(v[i]);
            }
        }
        k++;
    }
    return ans;
    // Write your code here!
}
