#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int r=0,c=0,lr=n,lc=m;
    int prev,curr;
    while(r<lr && c<lc)
    {
        if(r==lr-1 || c==lc-1)
        {
            break;
        }
        prev=mat[r+1][c];
        for(int i=c;i<lc;i++)
        {
            curr=mat[r][i];
            mat[r][i]=prev;
            prev=curr;
        }
        r++;
        for(int i=r;i<lr;i++)
        {
            curr=mat[i][lc-1];
            mat[i][lc-1]=prev;
            prev=curr;
        }
        lc--;
        if(r<lr)
        {
            for(int i=lc-1;i>=c;i--)
            {
                curr=mat[lr-1][i];
                mat[lr-1][i]=prev;
                prev=curr;
            }   
        }
         lr--;  
        if(c<lc)
        {
            for(int i=lr-1;i>=r;i--)
            {
                curr=mat[i][c];
                mat[i][c]=prev;
                prev=curr;
            }
        }
         c++;   
    }
    
    // Write your code here

}
