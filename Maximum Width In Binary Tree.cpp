#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *root)
{
    if(root==0)
    {
        return 0;
    }
    queue<pair<TreeNode<int> *,int>> q;
    q.push({root,0});
    int maxiw=0;
    int ans=0;
    while(!q.empty())
    {
        int si=q.size();
        ans=max(ans,si);
        auto mini=q.front().second;
        int first,last;
        for(int i=0;i<si;i++)
        {
            TreeNode<int> * b=q.front().first;
            int cind=q.front().second-mini;
            q.pop();
            if(i==0)
            {
                first=cind;
            }
            if(i==si-1)
            {
                last=cind;
            }
            if(b->left)
            {
                q.push({b->left,2*cind+1});
            }
            if(b->right)
            {
                q.push({b->right,2*cind+2});
            }
        }
        maxiw=max(maxiw,last-first+1);
    }
    // return maxiw;
    return ans;
    // Write your code here.
}
