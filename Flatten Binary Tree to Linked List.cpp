#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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

// void fbt(TreeNode<int> *root,TreeNode<int> *&prev)
// {
//     if(root==0)
//     {
//         return;
//     }
//     fbt(root->right,prev);
//     fbt(root->left,prev);
//     root->right=prev;
//     root->left=0;
//     prev=root;
   
// }
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> * curr=root;
    while(curr!=0)
    {
        if(curr->left)
        {
            TreeNode<int> *prev=curr->left;
            while(prev->right)
            {
                prev=prev->right;
            }
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=0;
        }
        curr=curr->right;
    }
    // curr=root;
    // while(curr!=0)
    // {
    //     curr->left=0;
    //     curr=curr->right;
    // }
    return root;
    // TreeNode<int> * prev=0;
    // fbt(root,prev);
    // return prev;
    // Write your code here.
}
