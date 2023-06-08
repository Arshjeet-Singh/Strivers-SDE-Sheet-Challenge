#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n=prices.size();
    int mp=INT_MIN,mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        mini=min(mini,prices[i]);
        mp=max(mp,prices[i]-mini);
    }    
    return mp;
    // Write your code here.
}
