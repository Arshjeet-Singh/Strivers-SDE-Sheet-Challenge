int calculateMinPatforms(int at[], int dt[], int n) 
{
    sort(at,at+n);
    sort(dt,dt+n);
    int ans=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(at[i]>dt[j])
        {
            // ans--;
            i++; j++;
        }
        else
        {
            ans++;
            i++;
        }
    }
    return ans;
    // Write your code here.
}
