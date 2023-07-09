#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if(root==0)
    {
        return ans;
    }
    queue<pair<TreeNode<int> *,pair<int,int>>> q;
    map<int,map<int,vector<int>>> mp;
    q.push({root, {0,0}});
    while(!q.empty())
    {
        int si=q.size();
        for(int i=0;i<si;i++)
        {
            auto a=q.front();
            q.pop();
            TreeNode<int> *fnode=a.first;
            int hd=a.second.first;
            int level=a.second.second;
            mp[hd][level].push_back(fnode->data);
            if(fnode->left)
            {
                q.push({fnode->left,{hd-1,level+1}});
            }
            if(fnode->right)
            {
                q.push({fnode->right,{hd+1,level+1}});
            }
        }
    }
    for(auto it:mp)
    {
        for(auto i:it.second)
        {
            for(auto j:i.second)
            {
                ans.push_back(j);
            }
        }
    }
    return ans;
    //    Write your code here.
}
