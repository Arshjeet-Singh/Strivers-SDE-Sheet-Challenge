#include <bits/stdc++.h> 
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode('\0');
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
            root->children[ind]=child;
        }
        inserth(word.substr(1),child);
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        inserth(word,root);
    }
    bool searchh(string word,TrieNode *root) 
    {
        if(word.length()==0)
        {
            if(root->isTerminal)
            {
                return true;
            }
            return false;
            // return root->isTerminal;
        }
        int ind=word[0]-'a';
        TrieNode *child;
        if(root->children[ind]!=0)
        {
            child=root->children[ind];
        }
        else
        {
            return false;
        }
        return searchh(word.substr(1),child);
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchh(word,root);
    }
    bool starth(string word,TrieNode *root) 
    {
        if(word.length()==0)
        {
            return true;
        }
        int ind=word[0]-'a';
        TrieNode *child;
        if(root->children[ind]!=0)
        {
            child=root->children[ind];
        }
        else
        {
            return false;
        }
        return starth(word.substr(1),child);
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return starth(prefix,root);
    }
};
string completeString(int n, vector<string> &a){
    string none="None";
    Trie t;
    // sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        string s=a[i];
        t.insert(s);
    }
    int len=0;
    string ans="";
    for(int i=0;i<n;i++)
    {
        string s=a[i];
        bool f=0;
        if(s.size()>=len)
        {
            for(int j=1;j<=s.size();j++)
        {
            if(t.search(s.substr(0,j)))
            {
                if(j==s.size())
                {
                    f=1;
                }
            }
            else
            {
                break;
            }
        }
        if(f)
        {
            if(s.size()>len)
            {
                len=s.size();
                ans=s;
            }
            else if(s.size()==len && ans>s)
            {
                ans=s;
            }
            // len=max(len,s.size());
        }
        }
        else{
            continue;
        }
        
    }
    if(ans.size())
    {
        return ans;
    }
    return none;
    // Write your code here.
}
