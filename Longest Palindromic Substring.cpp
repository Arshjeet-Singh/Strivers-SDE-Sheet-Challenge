string longestPalinSubstring(string str)
{
    int l,r;
    int n=str.size();
    int len=1;
    int startind=0;
    for(int i=1;i<n;i++)
    {
        l=i-1; r=i;
        while(l>=0 && r<n && str[l]==str[r])
        {
            if(r-l+1>len)
            {
                len=r-l+1;
                startind=l;
            }
            l--;
            r++;
        }
        l=i-1; r=i+1;
        while(l>=0 && r<n && str[l]==str[r])
        {
            if(r-l+1>len)
            {
                len=r-l+1;
                startind=l;
            }
            l--;
            r++;
        } 
    }
    return str.substr(startind,len);
    // Write your code here.
}
