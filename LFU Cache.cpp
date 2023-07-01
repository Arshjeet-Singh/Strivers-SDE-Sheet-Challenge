#include <bits/stdc++.h>
struct Node {
  int key, val, freq;
  Node *prev, *next;

  Node(int _key, int _val) { key = _key, val = _val, freq = 1; }
};

struct List {
  Node *head;
  Node *tail;
  int size;

  List() {
    size = 0;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  void addNewNode(Node *newNode) {
    Node *temp = head->next;
    newNode->next = temp;
    newNode->prev = head;
    head->next = newNode;
    temp->prev = newNode;
    size++;
  }

  void deleteNode(Node *delNode) {
    delNode->next->prev = delNode->prev;
    delNode->prev->next = delNode->next;
    size--;
  }
};

class LFUCache {
  unordered_map<int, Node *> mp;
  unordered_map<int, List *> freqList;
  int minFreq, cap, currSize;

public:
  LFUCache(int capacity) {
    minFreq = 0;
    cap = capacity;
    currSize = 0;
  }

  void updateList(Node *node) {
    mp.erase(node->key);
    freqList[node->freq]->deleteNode(node);

    if (freqList[node->freq]->size == 0 or node->freq == minFreq)
      minFreq++;

    List *newList = new List();
    if (freqList.count(node->freq + 1))
      newList = freqList[node->freq + 1];

    node->freq += 1;
    newList->addNewNode(node);
    freqList[node->freq] = newList;
    mp[node->key] = node;
  }

  int get(int key) {
    if (mp.count(key)) {
      Node *node = mp[key];
      int x = node->val;
      updateList(node);
      return x;
    }
    return -1;
  }

  void put(int key, int value) {
    if (cap == 0)
      return;

    else if (mp.count(key)) {
      Node *node = mp[key];
      node->val = value;
      updateList(node);
    }

    else {
      if (currSize == cap) {
        List *list = freqList[minFreq];
        mp.erase(list->tail->prev->key);
        list->deleteNode(list->tail->prev);
        currSize--;
      }

      currSize++;
      minFreq = 1;

      List *list = new List();
      if (freqList.count(minFreq))
        list = freqList[minFreq];

      Node *newNode = new Node(key, value);
      list->addNewNode(newNode);
      freqList[minFreq] = list;
      mp[key] = newNode;
    }
  }
};
// #include <bits/stdc++.h> 
// class node
// {
//     public:
//     int key,val,cnt;
        
//     node *next;
//     node *prev;
//     node(int key,int val)
//     {
//         this->key=key;
//         this->val=val;
//         cnt=1;
//     }
// };
// struct list{
//     // public:
//     int size;
//     node *head,*tail;
    
//     list()
//     {
//         head=new node(0,0);
//         tail=new node(0,0);
//         head->next=tail;
//         tail->prev=head;
//         size=0;
//     }
//     void addfront(node *newnode)
//     {
//         node *temp=head->next;
//         newnode->next=temp;
//         newnode->prev=head;
//         head->next=newnode;
//         temp->prev=newnode;
//         size++;
//     }
//     void removenode(node *delnode)
//     {
//         node *delprev=delnode->prev;
//         node *delnext=delnode->next;
//         delprev->next=delnext;
//         delnext->prev=delprev;
//         size--;
//     }
// };
// class LFUCache
// {
//     unordered_map<int,node*> keynode;
//     map<int,list*> freqmap;
//     int maxsizecache;
//     int minfreq;
//     int currsize;

// public:
//     LFUCache(int capacity)
//     {
//         maxsizecache=capacity;
//         minfreq=0;
//         currsize=0;
//         // Write your code here.
//     }
//     void updatefreqlistmap(node *currnode)
//     {
//         keynode.erase(currnode->key);
//         freqmap[currnode->cnt]=removenode(currnode);
//         if(currnode->cnt==minfreq && freqmap[currnode->cnt]==0)
//         {
//             minfreq++;
//         }
//         list *nexthighlist=new list();
//         if(freqmap.find(currnode->cnt+1)!=freqmap.end())
//         {
//             nexthighlist=freqmap[currnode->cnt+1];
//         }
//         currnode->cnt+=1;
//         nexthighlist->addfront(currnode);
//         freqmap[node->cnt]=nexthighlist;
//         keynode[currnode->key]=node;
//     }
//     int get(int key)
//     {
//         if(keynode.find()!=keynode.end())
//         {
//             node *currnode=keynode[key];
//             int val=node->val;
//             updatefreqlistmap(currnode);
//             return val;
//         }
//         return -1;
//         // Write your code here.
//     }

//     void put(int key, int value)
//     {
//         if(maxsizecache==0)
//         {
//             return;
//         }
//         if(keynode.find()!=keynode.end())
//         {
//             node *currnode=keynode[key];
//             node->val=value;
//             updatefreqlistmap(currnode);
//         }
//         else 
//         {
//             if(currsize==maxsizecache)
//             {
//                 list *li=freqmap[minfreq];
//                 keynode.erase(list->tail->prev->key);
//                 freqmap[minfreq]->removenode(list->tail->prev);
//                 currsize--;
//             }
//             currsize++;
//             minfreq=1;
//             list *  listfreq=new list();
//             if(freqmap.find(minfreq)!=freqmap.end())
//             {
//                 listfreq=freqmap[minfreq];
//             }
//             node *cnode=new node(key,value);
//             listfreq->addfront(cnode);
//             keynode[key]=node;
//             freqmap[minfreq]=listfreq;
//         }
//         // Write your code here.
//     }
// };
