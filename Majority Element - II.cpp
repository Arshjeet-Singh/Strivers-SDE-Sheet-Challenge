#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int cnt1=0,cnt2=0;
    int ele1=INT_MIN,ele2=INT_MIN;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(cnt1==0 && arr[i]!=ele2)
        {
            ele1=arr[i];
            cnt1=1;
        }
        else if(cnt2==0 && arr[i]!=ele1)
        {
            ele2=arr[i];
            cnt2=1;
        }
        else if(arr[i]==ele1)
        {
            cnt1++;
        }
        else if(arr[i]==ele2)
        {
            cnt2++;
        }
        else{
            cnt1--; cnt2--;
        }
    }
    cnt1=0; cnt2=0;
    int mini=n/3 +1;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele1)
        {
            cnt1++;
        }
        else if(arr[i]==ele2)
        {
            cnt2++;
        }
    }
     if(cnt1>=mini)
        {
            ans.push_back(ele1);
        }
         if(cnt2>=mini)
        {
            ans.push_back(ele2);
        }
        sort(ans.begin(),ans.end());
        return ans;
    // Write your code here.

}
