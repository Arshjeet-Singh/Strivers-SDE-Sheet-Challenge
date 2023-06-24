int lessthan(vector<int> r,int mid)
{
    int l=0,h=r.size()-1;
    while(l<=h)
    {
        int md=(l+h)/2;
        if(r[md]<=mid)
        {
            l=md+1;
        }
        else
        {
            h=md-1;
        }
    }
    return l;
}
int getMedian(vector<vector<int>> &matrix)
{
    int l=0,h=1e5;
    int n=matrix.size(),m=matrix[0].size();
    while(l<=h)
    {
        int mid=(l+h)/2;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=lessthan(matrix[i],mid);
        }
        if(cnt<=(n*m)/2)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }  
    return l; 
    // Write your code here.
}
