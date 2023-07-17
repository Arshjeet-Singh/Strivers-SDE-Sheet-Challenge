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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    if(root==0)
    {
        return -1;
    }
    if(root->data==x || root->data==y)
    {
        return root->data;
    }
    int lans=lowestCommonAncestor(root->left,x,y);
    int rans=lowestCommonAncestor(root->right,x,y);
    if(lans!=-1 && rans!=-1)
    {
        return root->data;
    }
    else if(lans!=-1 && rans==-1)
    {
        return lans;
    }
    else if(lans==-1 && rans!=-1)
    {
        return rans;
    }
    else
    {
        return -1;
    }
	//    Write your code here
}
