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
bool helper(TreeNode<int> *root, TreeNode<int> *leaf,stack<TreeNode<int>*> &s)
{
    s.push(root);
    if(root->left==0 && root->right==0)
    {
        if(root->data==leaf->data)
        {
            return true;
        }
        else
        {
            s.pop();
            return false;
        }
    }
    if(root->left)
    {
        if(helper(root->left,leaf,s))
        {
            return true;
        }
    }
    if(root->right)
    {
        if(helper(root->right,leaf,s))
        {
            return true;
        }
    }
    s.pop();
    return false;
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    if(root==0)
    {
        return root;
    }
    stack<TreeNode<int> *> s;
    bool b=helper(root,leaf,s);
    if(b==false)
    {
        return root;
    }
    TreeNode<int> * newroot=s.top();
    s.pop();
    TreeNode<int> * parent=newroot;
    while(!s.empty())
    {
        TreeNode<int> * currnode=s.top();
        s.pop();
        if(currnode->left==parent)
        {
            currnode->left=0;
            parent->left=currnode;
        }
        else
        {
            currnode->right=currnode->left;
            currnode->left=0;
            parent->left=currnode;
        }
        parent=parent->left;
    }
    return newroot;
	// Write your code here.
}
