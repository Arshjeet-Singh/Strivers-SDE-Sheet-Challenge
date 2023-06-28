#include<bits/stdc++.h>
class TrieNode{
    public:
    TrieNode *children[2];
};
class Trie{
    TrieNode *root;
    public:
    Trie()
    {
        root=new TrieNode();
    }
    void insert(int n)
    {
        TrieNode *node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(node->children[bit]==0)
            {
                node->children[bit]=new TrieNode();
                
            }
            node=node->children[bit];
        }
    }
    int getmax(int n)
    {
        TrieNode *node=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(node->children[1-bit])
            {
                ans=ans |(1<<i);
                node=node->children[1-bit];
            }
            else
            {
                node=node->children[bit];
            }
        }
        return ans;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	int n=arr.size();
	int q=queries.size();
	sort(arr.begin(),arr.end());
	vector<pair<int,pair<int,int>>> v;
	vector<int> ans(q,0);
    int ind=0;
    for (int i = 0; i < q; i++) 
	{
		v.push_back({queries[i][1],{queries[i][0],i}});
    }
	sort(v.begin(),v.end());
    Trie t;
    for(int i=0;i<q;i++)
	{
		// bool f=1;
		while(ind<n && arr[ind]<=v[i].first)
		{
			t.insert(arr[ind]);
			ind++;
		}
        if(ind==0)
        {
            ans[v[i].second.second]=-1;
        }
        else
        {
            int an=t.getmax(v[i].second.first);
            ans[v[i].second.second]=an;
        }
	
	}
	return ans;
	//	Write your coode here.
}
