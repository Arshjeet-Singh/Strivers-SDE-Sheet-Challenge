#include <bits/stdc++.h> 
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    int cend,cp;
    TrieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=0;
        }
        cend=0;
        cp=0;
    }
};
class Trie{
    TrieNode *root;
    public:

    Trie(){
        root=new TrieNode('\0');
        // Write your code here.
    }
    void inserth(string word,TrieNode *root)
    {
        if(word.size()==0)
        {
            root->cp++;
            root->cend+=1;
            return;
        }
        TrieNode *child;
        int ind=word[0]-'a';
        if(root->children[ind]!=0)
        {
            // root->children[ind]->cnt+=1;
            child=root->children[ind];
        }
        else
        {
            child=new TrieNode(word[0]);
            // child->cnt+=1;
            root->children[ind]=child;
        }
        root->cp++;
        inserth(word.substr(1),child);
        // Write your code here.
    }
    void insert(string &word){
        inserth(word,root);
        
        // Write your code here.
    }
    int cw(string word,TrieNode*root)
    {
        if(word.size()==0)
        {
            return root->cend;
        }
        TrieNode *child;
        int ind=word[0]-'a';
        if(root->children[ind]!=0)
        {
            child=root->children[ind];
        }
        else
        {
            return 0;
        }
        return cw(word.substr(1),child);
    }
    int countWordsEqualTo(string &word){
        return cw(word,root);
        // Write your code here.
    }
    int cws(string word,TrieNode*root)
    {
        if(word.size()==0)
        {
            return root->cp;
        }
        TrieNode *child;
        int ind=word[0]-'a';
        if(root->children[ind]!=NULL)
        {
            child=root->children[ind];
        }
        else
        {
            return 0;
        }
        return cws(word.substr(1),child);
    }
    int countWordsStartingWith(string &word)
    {
        return cws(word,root);
        // Write your code here.
    }
    void eraseh(string word,TrieNode *root)
    {
        if(word.size()==0)
        {
            root->cp--;
            root->cend--;
            return;
        }
        TrieNode *child;
        int ind=word[0]-'a';
        if(root->children[ind]!=NULL)
        {
            root->cp--;
            child=root->children[ind];
        }
        else
        {
            return;
        }
        eraseh(word.substr(1),child);
    }
    void erase(string &word){
        eraseh(word,root);
        // Write your code here.
    }
};
