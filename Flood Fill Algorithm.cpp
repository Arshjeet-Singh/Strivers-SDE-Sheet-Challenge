void dfs(vector<vector<int>> &image, int x, int y, int nc,vector<vector<bool>> &vis,int oc)
{
    if(x>=0 && y>=0 && x<image.size() && y<image[0].size() && !vis[x][y] && image[x][y]==oc)
    {
        vis[x][y]=1;
        image[x][y]=nc;
        dfs(image,x+1,y,nc,vis,oc);
        dfs(image,x-1,y,nc,vis,oc);
        dfs(image,x,y+1,nc,vis,oc);
        dfs(image,x,y-1,nc,vis,oc);
    }
    else{
        return;
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int n=image.size();
    int m=image[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    dfs(image,x,y,newColor,vis,image[x][y]);
    return image;
    // Write your code here.
}
