#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void travel(TreeNode *root,vector<int> &ans)
{
    if(root==0)
    {
        return;
    }
    travel(root->left,ans);
    ans.push_back(root->data);
    travel(root->right,ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    travel(root,ans);
    return ans;

    // Write your code here.
}
