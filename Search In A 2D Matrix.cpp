bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n=mat.size();
    int m=mat[0].size();
    int l=0,h=n*m-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(mat[mid/m][mid%m]==target)
        {
            return true;
        }
        else if(mat[mid/m][mid%m]<target)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
            // i++; j--;
        }
    }
    return false;

        
}
