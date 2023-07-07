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
int height(TreeNode<int> *root)
{
    if(root==0)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
pair<int,int> df(TreeNode<int> *root)
{
    if(root==0)
    {
        return {0,0};
    }
    pair<int,int> l=df(root->left);
    pair<int,int> r=df(root->right);
    int op1=l.first;
    int op2=r.first;
    int op3=l.second+r.second;
    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=1+max(l.second,r.second);
    return ans;
	// Write Your Code Here.
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    return df(root).first;
    // if(root==0)
    // {
    //     return 0;
    // }
    // int op1=diameterOfBinaryTree(root->left);
    // int op2=diameterOfBinaryTree(root->right);
    // int op3=height(root->left)+height(root->right);
    // return max(op1,max(op2,op3));
	// Write Your Code Here.
}
