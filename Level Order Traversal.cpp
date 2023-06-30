#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root==0)
    {
        return ans;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode<int> * a=q.front();
        q.pop();
        ans.push_back(a->val);
        if(a->left)
        {
            q.push(a->left);
        }
        if(a->right)
        {
            q.push(a->right);
        }
    }
    return ans; 
    //  Write your code here.
}
