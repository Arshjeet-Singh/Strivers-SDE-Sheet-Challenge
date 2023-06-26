/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

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
