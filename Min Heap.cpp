#include <bits/stdc++.h> 
class heap{
    public:
    int arr[100000+1];
    int size;
    heap()
    {
        arr[0]=-1;
        size=0;
    }
    void insert(int val)
    {
        size+=1;
        arr[size]=val;
        int ind=size;
        while(ind>1)
        {
            int p=ind/2;
            if(arr[p]>arr[ind])
            {
                swap(arr[p],arr[ind]);
                ind=p;
            }
            else
            {
                return;
            }
        }
        return;
    }
    int del()
    {
        if(size==0)
        {
            return -1;
        }
        int mini=arr[1];
        arr[1]=arr[size];
        size-=1;
        int i=1;
        while(i<size)
        {
            int l=2*i,r=2*i+1;
            int larger;
            if(arr[l]>arr[r])
            {
                larger=l;
            }
            else
            {
                larger=r;
            }
            if(larger<size && arr[larger]<arr[i])
            {
                swap(arr[larger],arr[i]);
                i=larger;
            }
            else
            {
                return mini;
            }
            // if(l<size && arr[l]<arr[i])
            // {
            //     swap(arr[l],arr[i]);
            //     i=l;
            // }
            // else if(r<size && arr[r]<arr[i])
            // {
            //     swap(arr[r],arr[i]);
            //     i=r;
            // }
            // else
            // {
            //     return mini;
            // }
        }
        return mini;
    }
};
vector<int> minHeap(int n, vector<vector<int>>& q) {
    heap h;
    vector<int> v;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        if(q[i][0]==0)
        {
            pq.push(q[i][1]);
        } else {
          int a = pq.top();
          pq.pop();
          v.push_back(a);
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     if(q[i][0]==0)
    //     {
    //         h.insert(q[i][1]);
    //     }
    //     else
    //     {
    //         int a=h.del();
    //          v.push_back(a);
    //         // if(a!=-1)
    //         // {
               
    //         // }
    //     }
    // }
    return v;
    // Write your code here.
}
