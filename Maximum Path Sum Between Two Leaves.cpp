#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int help(TreeNode<int> *root,long long int &maxi)
{
    if(root==0)
    {
        return 0;
    }

    long long int lans=help(root->left,maxi);
    long long int rans=help(root->right,maxi);
    maxi=max(maxi,root->val+lans+rans);
    return root->val+max(lans,rans);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    if(root==0 || root->left==0 || root->right==0)
    {
        return -1;
    }
    long long int maxi=0;
    int a=help(root,maxi);
    return maxi;
    // Write your code here.
}
