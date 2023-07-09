#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root==0)
    {
        return ans;
    }
    map<int,int> topnode;
    queue<pair<TreeNode<int> *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        auto a=q.front();
        q.pop();
        TreeNode<int> * fnode=a.first;
        int hd=a.second;
        if(topnode.find(hd)==topnode.end())
        {
            topnode[hd]=fnode->val;
        }
        if(fnode->left)
        {
          q.push({fnode->left, hd - 1});
        }
        if(fnode->right)
        {
            q.push({fnode->right, hd+1});
        }
    }
    for(auto it:topnode)
    {
        ans.push_back(it.second);
    }
    return ans;
    // Write your code here.
}
