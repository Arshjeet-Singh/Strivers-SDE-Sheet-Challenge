#include<bits/stdc++.h>
class LRUCache
{
    class node{
        public:
        int key,val;
        node *next,*prev;
        node(int key,int val)
        {
            this->key=key;
            this->val=val;
        }
    };
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int cap;
    unordered_map<int,node *> mp;
public:
    LRUCache(int capacity)
    {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        // Write your code here
    }
    void addnode(node *newnode)
    {
        node *temp=head->next;
        head->next=newnode;
        newnode->next=temp;
        newnode->prev=head;
        temp->prev=newnode;
    }
    void deletenode(node *delnode)
    {
        node *delprev=delnode->prev;
        node *delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    int get(int ke)
    {
        if(mp.find(ke)!=mp.end())
        {
            node *resnode=mp[ke];
            int res=resnode->val;
            mp.erase(ke);
            deletenode(resnode);
            addnode(resnode);
            mp[ke]=head->next;
            return res;
        }
        return -1;
        // Write your code here
    }
    void put(int ke, int value)
    {
        if(mp.find(ke)!=mp.end())
        {
            node *existingnode=mp[ke];
            mp.erase(ke);
            deletenode(existingnode);
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(ke,value));
        mp[ke]=head->next;
        // Write your code here
    }
};
