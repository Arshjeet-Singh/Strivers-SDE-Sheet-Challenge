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

class BSTiterator
{
    public:
    stack<TreeNode<int> *> s;
    BSTiterator(TreeNode<int> *root)
    {
        while(root!=0)
        {
            s.push(root);
            root=root->left;
        }
        // write your code here
    }

    int next()
    {
        TreeNode<int> * ans=s.top();
        s.pop();
        if(ans->right)
        {
            TreeNode<int> * tra=ans->right;
            while(tra!=0)
            {
                s.push(tra);
                tra=tra->left;
            }
        }
        return ans->data;
        // write your code here
    }

    bool hasNext()
    {
        return !s.empty();
        // write your code here
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
