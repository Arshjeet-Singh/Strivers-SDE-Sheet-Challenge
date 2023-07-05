#include<bits/stdc++.h>
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    int ccount;
    bool isTerminal;
    TrieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        ccount=0;
        isTerminal=false;
    }
};
class Trie {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie(char ch) {
        root=new TrieNode(ch);
    }
    void inserth(string word,TrieNode *root)
    {
        if(word.length()==0)
        {
            root->isTerminal=true;
            return;
        }
        TrieNode *child;
        int ind=word[0]-'a';
        if(root->children[ind]!=NULL)
        {
            child=root->children[ind];
        }
        else
        {
            child=new TrieNode(word[0]);
            root->ccount++;
            root->children[ind]=child;
        }
        inserth(word.substr(1),child);
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        inserth(word,root);
    }
    void lcp(string first,string &ans)
    {
        for(int i=0;i<first.length();i++)
        {
            char cha=first[i];
            if(root->ccount==1)
            {
                ans.push_back(cha);
                int ind=cha-'a';
                root=root->children[ind];
            }
            else{
                break;
            }
            if(root->isTerminal)
            {
                break;
            }
        }
    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Trie *t=new Trie('\0');
    // string ans="";
    // for(int i=0;i<n;i++)
    // {
    //     t->insert(arr[i]);
    // }
    // string first=arr[0];
    // t->lcp(first,ans);
    string ans="";
    for(int i=0;i<arr[0].length();i++)
    {
        char ch=arr[0][i];
        bool f=1;
        for(int j=1;j<n;j++)
        {
            if(i>arr[j].size() || arr[j][i]!=ch)
            {
                f=0;
            }
        }
        if(f==0)
        {
            break;

        }
        ans+=ch;
    }
    return ans;
    // Write your code here
}


