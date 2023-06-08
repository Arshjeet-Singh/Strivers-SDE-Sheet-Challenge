#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long ans=0,sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<0)
        {
            sum=0;
        }
        ans=max(ans,sum);
    }
    return ans;
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
}
