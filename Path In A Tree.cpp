#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool help(TreeNode<int> *root, int x,vector<int> &ans)
{
  if (root == 0) 
  {
    return false;
  }
  ans.push_back(root->data);
  if(root->data==x)
  {
	  return true;
  }
//   bool a = help(root->left, x, ans);
//   bool b = help(root->right, x, ans);
  if (help(root->left, x, ans) || help(root->right, x, ans))
  {
	return true;
  }
		ans.pop_back();
		return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int> ans;
	if(root==0)
	{
		return ans;
	}
	//m2
	bool b=help(root,x,ans);
	return ans;
	//m1
	// unordered_map<TreeNode<int> *,TreeNode<int> *> mp;
	// queue<TreeNode<int> *> q;
	// q.push(root);
	// mp[root]=0;
	// TreeNode<int> * temp;
	// while(!q.empty())
	// {
	// 	auto a=q.front();
	// 	q.pop();
	// 	if(a->data==x)
	// 	{
	// 		temp=a;
	// 		break;
	// 	}
	// 	if(a->left)
	// 	{
	// 		mp[a->left]=a;
	// 		q.push(a->left);
	// 	}
	// 	if(a->right)
	// 	{
	// 		mp[a->right]=a;
	// 		q.push(a->right);
	// 	}
	// }
	// TreeNode<int> * tra=temp;
	// while(tra!=0)
	// {
	// 	ans.push_back(tra->data);
	// 	tra=mp[tra];
	// }
	// reverse(ans.begin(),ans.end());
	// return ans;
    // Write your code here.
}
