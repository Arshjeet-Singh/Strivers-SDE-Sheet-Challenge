#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if(root==0)
    {
        return ans;
    }
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty())
    {
        int si=q.size();
        for(int i=0;i<si;i++)
        {
            TreeNode<int> * a=q.front();
            q.pop();
            if(i==0)
            {
                ans.push_back(a->data);
            }
              if(a->left)
            {
                q.push(a->left);
            }
            if(a->right)
            {
                q.push(a->right);
            }
          
        }
    }
    return ans;
    //    Write your code here
}
