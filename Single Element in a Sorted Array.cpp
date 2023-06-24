int singleNonDuplicate(vector<int>& arr)
{
	int n=arr.size();
	if(n==1)
	{
		return arr[0];
	}
	if(arr[0]!=arr[1])
	{
		return arr[0];
	}
	if(arr[n-1]!=arr[n-2])
	{
		return arr[n-1];
	}
	int l=1,h=n-2;
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1])
		{
			return arr[mid];
		}
		if((mid%2==1 && arr[mid]==arr[mid-1])||(mid%2==0 && arr[mid]==arr[mid+1]) )
		{
			l=mid+1;
		}
		else
		{
			h=mid-1;
		}
	}
	return -1;
	// for(int i=0;i<n;i++)
	// {
	// 	if(i==0)
	// 	{
	// 		if(arr[i]!=arr[i+1])
	// 		{
	// 			return arr[i];
	// 		}
	// 	}
	// 	else if(i==n-1)
	// 	{
	// 		if(arr[i]!=arr[i-1])
	// 		{
	// 			return arr[i];
	// 		}
	// 	}
	// 	else
	// 	{
	// 		if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1])
	// 		{
	// 			return arr[i];
	// 		}
	// 	}
	// }
	// return -1;
	// long long int xo=arr[0];
	// for(int i=1;i<n;i++)
	// {
	// 	xo=xo^arr[i];
	// }
	// return xo;
	// Write your code here
}
