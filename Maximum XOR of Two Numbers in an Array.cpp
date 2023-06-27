#include <bits/stdc++.h> 
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
int maximumXor(vector<int> A)
{
    int n=A.size();
    Trie t;
    for(int i=0;i<n;i++)
    {
        t.insert(A[i]);
    }
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,t.getmax(A[i]));
    }
    return maxi;
    // Write your code here.   
}
