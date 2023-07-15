int help(int i,int j,string str1, string str2,vector<vector<int>> &dp)
{
    if(i==str1.size())
    {
        return str2.size()-j;
    }
    if(j==str2.size())
    {
        return str1.size()-i;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(str1[i]==str2[j])
    {
        return dp[i][j]=help(i+1,j+1,str1,str2,dp);
    }
    else
    {
        int ins=1+help(i, j+1, str1, str2,dp);
        int del=1+help(i+1,j,str1,str2,dp);
        int rep=1+help(i+1,j+1,str1,str2,dp);
        return dp[i][j]=min(ins,min(del,rep));
    }
}
int editDistance(string str1, string str2)
{
    int n=str1.size(),m=str2.size();
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<m;j++)
    {
        dp[n][j]=m-j;
    }
    for(int i=0;i<n;i++)
    {
        dp[i][m]=n-i;
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(str1[i]==str2[j])
            {
                dp[i][j]=dp[i+1][j+1];
            }
            else
            {
                int ins=1+dp[i][j+1];
                int del=1+dp[i+1][j];
                int rep=1+dp[i+1][j+1];
                dp[i][j]=min(ins,min(del,rep));
            }
        }
    }
    return dp[0][0];
    // return help(0,0,str1,str2,dp);
    //write you code here
}
