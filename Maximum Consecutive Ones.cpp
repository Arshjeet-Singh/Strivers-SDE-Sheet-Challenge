int longestSubSeg(vector<int> &arr , int n, int k){
    int i=0,j=0,flip=0,ans=0;
    while(i<n)
    {
        if(arr[i]==0)
        {
            flip++;
        }
        while(flip>k)
        {
            if(arr[j]==0)
            {
                flip--;
            }
            j++;
        }
        ans=max(ans,i-j+1);
        i++;
    }
    return ans;
    // Write your code here.
}
