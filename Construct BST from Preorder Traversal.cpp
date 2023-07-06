#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* help(vector<int> &preOrder,int l,int h)
{
    if(l>h)
    {
        return 0;
    }
    int mid=(l+h)/2;
    TreeNode<int>* root=new TreeNode<int>(preOrder[mid]);
    root->left=help(preOrder,l,mid-1);
    root->right=help(preOrder,mid+1,h);
    return root;

}
TreeNode<int>* help1(vector<int> &preOrder,int &i,int b)
{
    if(i==preOrder.size() || preOrder[i]>b)
    {
        return 0;
    }
    TreeNode<int>* root=new TreeNode<int>(preOrder[i++]);
    root->left=help1(preOrder,i,root->data);
    root->right=help1(preOrder,i,b);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // sort(preOrder.begin(),preOrder.end());
    // int n=preOrder.size();
    // return help(preOrder,0,n-1);
    //m2 (optimised)
    int i=0,bound=INT_MAX;
    return help1(preOrder,i,bound);
    // Write your code here.
}
