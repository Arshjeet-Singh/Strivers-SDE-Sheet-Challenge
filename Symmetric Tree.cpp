/*****************************************************

    Following is the Binary Tree node structure:
    
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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool sym(BinaryTreeNode<int>* left,BinaryTreeNode<int>* right)
{
    if(left==0 || right==0)
    {
        return left==right;
    }
    if(left->data!=right->data)
    {
        return false;
    }
    return sym(left->left,right->right)&&sym(left->right,right->left);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    return root==0 || sym(root->left,root->right);
    // if(root==0)
    // {
    //     return 1;
    // }
    // if(root->left==0 && root->right!=0)
    // {
    //     return 0;
    // }
    // if(root->left!=0 && root->right==0)
    // {
    //     return 0;
    // }
    // if(root->left==0 && root->right==0)
    // {
    //     return 1;
    // }
    // BinaryTreeNode<int>* l=root->left;
    // BinaryTreeNode<int>* r=root->right;
    // while(l!=0 && r!=0 && l->data==r->data)
    // {
    //     l=l->left;
    //     r=r->right;
    // }
    // if(l!=0 ||r!=0)
    // {
    //     return 0;
    // }
    // l=root->left;
    // r=root->right;
    // while(l!=0 && r!=0 && l->data==r->data)
    // {
    //     l=l->right;
    //     r=r->left;
    // }
    // if(l!=0 ||r!=0)
    // {
    //     return 0;
    // }
    // return 1;
    // Write your code here.    
}
