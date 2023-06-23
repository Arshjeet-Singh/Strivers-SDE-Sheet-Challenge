#include <bits/stdc++.h> 
bool safe(int node,vector<vector<int>> &mat,vector<int> &color,int n,int m,int col)
{
    for(int k=0;k<n;k++)
    {
        if(k!=node && mat[node][k] && color[k]==col)
        {
            return false;
        }
    }
    return true;
}
bool check(int node,vector<vector<int>> &mat,vector<int> &color,int n,int m)
{
    if(node==n)
    {
        return true;
    }
    for(int i=1;i<=m;i++)
    {
        if(safe(node,mat,color,n,m,i))
        {
            color[node]=i;
            bool ch=check(node+1,mat,color,n,m);
            if(ch)
            {
                return true;
            }
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    string yes="YES",no="NO";
    // unordered_map<int,list<int>> adj;
    int n=mat.size();
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if(mat[i][j])
    //         {
    //             adj[i].push_back(j);
    //             adj[j].push_back(i);
    //         }    
    //     }
    //     // int u=mat[i][0];
    //     // int v=mat[i][1];
    // }
    vector<int> color(n,0);
    bool ch=check(0,mat,color,n,m);
    if(ch)
    {
        return yes;
    }
    return no;
    // Write your code here
}
