// #include<bits/stdc++.h>
// struct TrieNode
// {
//    TrieNode * child[26];
//    TrieNode(){
//        for(int i = 0; i<26;i++){
//            child[i] = NULL;
//        }
//    }
   
// };

// int distinctSubstring(string &word) {
//    //  Write your code here.
//    TrieNode * root  = new TrieNode();
//    int cnt= 0;
//    for(int i = 0 ;i<word.size();i++){
//        TrieNode * curr = root;
//        for(int j = i ; j<word.size();j++){
//            int index = word[j] - 'a';
//            if(curr->child[index] == NULL){
//                cnt++;
//                curr->child[index] = new TrieNode();
//            }
//             curr =curr->child[index];
//        }
//    }
//    return cnt;
// }
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
    void inserth(string word,TrieNode *root,int &cnt)
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
            // return;
        }
        else
        {
            child=new TrieNode(word[0]);
            cnt++;
            root->children[ind]=child;
        }
        inserth(word.substr(1),child,cnt);
    }
    /** Inserts a word into the trie. */
    void insert(string word,int &cnt) {
        inserth(word,root,cnt);
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
int distinctSubstring(string &word) {
    int cnt=0;
    // Trie t;
    TrieNode *root;
    root=new TrieNode('\0');
    for(int i=0;i<word.size();i++)
    {
        TrieNode *curr=root;
        for(int j=i;j<word.size();j++)
        {
            int ind=word[j]-'a';
            TrieNode *child;
            if(curr->children[ind]==0)
            {
                child=new TrieNode(word[j]);
                cnt++;
                curr->children[ind]=child;
                child=root->children[ind];
            }
            else
            {
                
            }
            curr=curr->children[ind];
        //    t.insert(word.substr(i,j-i+1),cnt); 
        }
    }
    // cout<<endl;
    return cnt;
    //  Write your code here.
}
