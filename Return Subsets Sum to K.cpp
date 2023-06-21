void help(int ind,vector<int> &num,int n, int k,vector<int> &v,vector<vector<int>>&ans)
{
    if(ind>=n)
    {
        int s=0;
        for(int i=0;i<v.size();i++)
        {
            s+=v[i];
        }
        if(s==k)
        {
            ans.push_back(v);
        }
        return;
    }
    v.push_back(num[ind]);
    help(ind+1,num,n,k,v,ans);
    v.pop_back();
    help(ind+1,num,n,k,v,ans);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int> v;
    vector<vector<int>> ans;
    help(0,arr,n,k,v,ans);
    // sort(ans.begin(),ans.end());
    return ans; 
    // Write your code here.
}
