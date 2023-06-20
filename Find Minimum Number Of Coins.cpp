#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int coin[]={1000,500,100,50,20,10,5,2,1};
    int k=amount,i=0,ans=0;
    while(k>0)
    {
        if(k>=coin[i])
        {
            k-=coin[i];
            ans++;
        }
        else{
            i++;
        }
    }
    return ans;
    // Write your code here
}
