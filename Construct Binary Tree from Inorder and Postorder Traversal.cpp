/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* help(int i,int j,int &pi,vector<int>& postOrder, vector<int>& inOrder)
{
     if(i>j || pi<0)
     {
          return 0;
     }
     int ele=postOrder[pi--];
     TreeNode<int>* root=new TreeNode<int>(ele);
     int ind=-1;
     for(int k=0;k<inOrder.size();k++)
     {
          if(ele==inOrder[k])
          {
               ind=k;
               break;
          }
     }
     root->right=help(ind+1,j,pi,postOrder,inOrder);
     root->left=help(i,ind-1,pi,postOrder,inOrder);
     return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
     int pi=postOrder.size()-1;
     int n=postOrder.size();
     return help(0,n-1,pi,postOrder,inOrder);
	// Write your code here.
}
