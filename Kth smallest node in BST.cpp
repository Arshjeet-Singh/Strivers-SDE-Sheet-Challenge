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

int help(TreeNode<int> *root, int k,int &cnt)
{
    if(root==0)
    {
        return -1;
    }
    int l=help(root->left,k,cnt);
    if(l!=-1)
    {
        return l;
    }
    cnt++;
    if(cnt==k)
    {
        return root->data;
    }
    return help(root->right,k,cnt);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int cnt=0;
    if(root==0)
    {
        return 0;
    }
    return help(root,k,cnt);
	//	Write the code here.
}
