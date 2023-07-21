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
TreeNode<int> * help(int i,int j,int &pi,vector<int> &inorder, vector<int> &preorder)
{
    if(i>j)
    {
        return 0;
    }
    if(pi>=preorder.size())
    {
        return 0;
    }
    int ele=preorder[pi++];
    TreeNode<int> *root=new TreeNode<int>(ele);
    int ind=-1;
    for(int k=0;k<inorder.size();k++)
    {
        if(ele==inorder[k])
        {
            ind=k;
            break;
        }
    }
    root->left=help(i,ind-1,pi,inorder,preorder);
    root->right=help(ind+1,j,pi,inorder,preorder);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n=inorder.size();
    int pi=0;
    return help(0,n-1,pi,inorder,preorder);
	//    Write your code here
}
