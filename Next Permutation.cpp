#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int ind=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(permutation[i]<permutation[i+1])
        {
            ind=i;
            break;
        }
    }
    if(ind==-1)
    {
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }
    for(int i=n-1;i>=ind;i--)
    {
        if(permutation[i]>permutation[ind])
        {
            swap(permutation[i],permutation[ind]);
            break;
        }
    }
    reverse(permutation.begin()+ind+1,permutation.end());
    return permutation;
    // vector<int> h=permutation;
    // sort(h.begin(),h.end());
    // unordered_map<int,int> mp,mp1;
    // for(int i=0;i<n;i++)
    // {
    //     mp[permutation[i]]=i;
    //     mp1[h[i]]=i;
    // }
    // for(int i=n-1;i>=0;i--)
    // {
    //     if(permutation[i]!=h[n-1])
    //     {
    //         int ind=mp[permutation[i]]+1;
    //         permutation[ind]=permutation[i];
    //         permutation[i]+=1;
    //         break;
    //     }
        // for(int j=n-1;j>=0;j--)
        // {
            
        //     else if(permutation[i]==h[j])
        //     {
        //         permutation[i]=h[j+1];
        //     }
    // }
    // return permutation;
    //  Write your code here.
}
