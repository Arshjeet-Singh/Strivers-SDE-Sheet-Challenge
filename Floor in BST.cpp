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

int floorInBST(TreeNode<int> * root, int x)
{
    int floor=-1;
    while(root!=0)
    {
        if(root->val==x)
        {
            floor=root->val;
            break;
        }
        else if(root->val>x)
        {
            root=root->left;
        }
        else if(root->val<x)
        {
            floor=root->val;
            root=root->right;
        }
    }
    return floor;
    // Write your code here.
}