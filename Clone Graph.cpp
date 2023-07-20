#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
// void dfs(graphNode *ans,graphNode *node,vector<node *> &vis)
// {
// 	vis[node->val]=ans;
// 	for(auto x:node->neighbours)
// 	{
// 		if(vis[x->val]==0)
// 		{
// 			graphNode *newnode=new graphNode(x->val);
// 			ans->neighbours.push_back(newnode);
// 			dfs(newnode,x,vis);
// 		}
// 		else
// 		{
// 			ans->neighbours.push_back(vis[x->val])
// 		}
// 	}
// }
graphNode *rec (graphNode *node,unordered_map<graphNode *,graphNode*> &mp)
{
	graphNode *newnode=new graphNode(node->data);
	mp[node]=newnode;
	vector<graphNode*> v;
	for(auto it:node->neighbours)
	{
		if(mp.find(it)!=mp.end())
		{
			v.push_back(mp[it]);
		}
		else
		{
			v.push_back(rec(it,mp));
		}
	}
	newnode->neighbours=v;
	return newnode;
}
graphNode *cloneGraph(graphNode *node)
{
	if(node==0)
	{
		return 0;
	}
	// vector<node *> vis(1000,0);
	// graphNode *ans=new graphNode(node->val);
	// dfs(ans,graphNode,vis);
	// return ans;
	unordered_map<graphNode *,graphNode*> mp;
	return rec(node,mp);
    // Write your code here.
}
