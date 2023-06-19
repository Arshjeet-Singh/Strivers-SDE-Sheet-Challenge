#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // long leftmax=0,rightmax=0;
    // long left=0,right=n-1,res=0;
    // while(left<=right)
    // {
    //     if(arr[left]<=arr[right])
    //     {
    //         if(arr[left]>=leftmax)
    //         {
    //             leftmax=arr[left];
    //         }
    //         else
    //         {
    //             res+=leftmax-arr[left];

    //         }
    //         left++;
    //     }
    //     else
    //     {
    //         if(arr[right]>=rightmax)
    //         {
    //             rightmax=arr[right];
    //         }
    //         else
    //         {
    //             res+=rightmax-arr[right];
    //         }
    //         right--;
    //     }
    // }
    // return res;
    //non optimal
    vector<long> left(n,0),right(n,0);
    left[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],arr[i]);
    }
    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],arr[i]);
    }
    long res=0;
    for(int i=0;i<n;i++)
    {
        res+=min(left[i],right[i])-arr[i];
    }
    return res;
    // Write your code here.
}
