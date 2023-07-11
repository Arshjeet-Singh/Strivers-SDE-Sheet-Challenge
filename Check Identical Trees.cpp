#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1==0 || root2==0)
    {
        return root1==root2;
    }
    
    // if(root1->data==root2->data)
    // {
        return (root1->data==root2->data) &&identicalTrees(root1->left,root2->left) && identicalTrees(root1->right, root2->right);
    // }
    // queue<BinaryTreeNode<int>*> q1,q2;
    // q1.push(root1);
    // q2.push(root2);
    // while(!q1.empty() && !q2.empty())
    // {
    //     auto a=q1.front();
    //     auto b=q2.front();
    //     q1.pop();
    //     q2.pop();
    //     if(a->data!=b->data)
    //     {
    //         return false;
    //     }
    //     if(a->left && b->left)
    //     {
    //         q1.push(a->left);
    //         q2.push(b->left);
    //     }
    //     else
    //     {
    //         return false;
    //     }
    //     if(a->right && b->right)
    //     {
    //         q1.push(a->right);
    //         q2.push(b->right);
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
    // return true;
    // Write your code here. 	 
}
