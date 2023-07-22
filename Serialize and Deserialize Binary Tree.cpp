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
#include<bits/stdc++.h>
string serializeTree(TreeNode<int> *root)
{
    if(root==0)
    {
        return "";
    }
    queue<TreeNode<int> *> q;
    q.push(root);
    string s="";
    while(!q.empty())
    {
        TreeNode<int> * a=q.front();
        q.pop();
        if(a==0)
        {
            s+="#,";
        }
        else
        {
            s+=(to_string(a->data)+',');
        }
        if(a!=0)
        {
            q.push(a->left);
            q.push(a->right);
        }
    }
    return s;
 //    Write your code here for serializing the tree

}

TreeNode<int>* deserializeTree(string data)
{
    if(data.size()==0)
    {
        return 0;
    }
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode<int>* root=new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>* a=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#")
        {
            a->left=0;
        }
        else
        {
            TreeNode<int>* lnode=new TreeNode<int>(stoi(str));
            a->left=lnode;
            q.push(lnode);
        }
        getline(s,str,',');
        if(str=="#")
        {
            a->right=0;
        }
        else
        {
            TreeNode<int>* rnode=new TreeNode<int>(stoi(str));
            a->right=rnode;
            q.push(rnode);
        }
    }
    return root;
 //    Write your code here for deserializing the tree

}



