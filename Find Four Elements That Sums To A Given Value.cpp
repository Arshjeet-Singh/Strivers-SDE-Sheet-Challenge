#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    string yes="Yes",no="No";
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        if(i!=0 && arr[i]==arr[i-1])
        {
            continue;
        }
        for(int j=i+1;j<n;j++)
        {
            if(j!=i+1 && arr[j]==arr[j-1])
            {
                continue;
            }
            int k=j+1,l=n-1;
            while(k<l)
            {
                if(arr[i]+arr[j]+arr[k]+arr[l]==target)
                {
                    return yes;
                    k++; l--;
                    while(k<l && arr[k]==arr[k-1])
                    {
                        k++;
                    }
                    while (k < l && arr[l] == arr[l + 1]) {
                      l--;
                    }
            }
                else if(arr[i]+arr[j]+arr[k]+arr[l]<target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    return no;
    // Write your code here.
}
