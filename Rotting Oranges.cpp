#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    int cone=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
              q.push({{i, j}, 0});
              vis[i][j]=2;
            }
            else if(grid[i][j]==1)
            {
                cone++;
            }
        }
    }
    int done=0;
    int maxtime=0;
    int dr[]={1,0,-1,0};
    int dc[]={0,-1,0,1};
    while(!q.empty())
    {
        // auto a=q.front();
        int row=q.front().first.first;
        int col=q.front().first.second;
        int time=q.front().second;
        maxtime=max(maxtime,time);
        q.pop();
        for(int i=0;i<4;i++)
        {
            int r=row+dr[i];
            int c=col+dc[i];
            if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0 && grid[r][c]==1)
            {
                q.push({{r,c},time+1});
                vis[r][c]=2;
                done++;
            }
        }
    }
    if(done==cone)
    {
        return maxtime;
    }
    return -1;
    // Write your code here. 
}
