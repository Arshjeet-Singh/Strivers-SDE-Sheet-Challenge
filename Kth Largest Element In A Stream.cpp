#include <bits/stdc++.h> 
class Kthlargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int cnt;
public:
    Kthlargest(int k, vector<int> &arr) {
        cnt=k;
        for(int i=0;i<arr.size();i++)
        {
            pq.push(arr[i]);
            if(pq.size()>cnt)
            {
                pq.pop();
            }
        }
       // Write your code here.
    }

    void add(int num) {
        pq.push(num);
            if(pq.size()>cnt)
            {
                pq.pop();
            }
        // Write your code here.
    }

    int getKthLargest() {
        return pq.top();
       // Write your code here.
    }

};
