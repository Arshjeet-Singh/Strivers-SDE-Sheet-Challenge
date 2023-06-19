int removeDuplicates(vector<int> &arr, int n) {
	int i=0,cnt=1,k=0;
	while(i<n-1)
	{
		while(arr[i]==arr[i+1])
		{
			i++;
		}
		arr[k++]=arr[i];
		i++;
	}
	if(arr[n-1]!=arr[n-2])
	{
		k++;
	}
	return k;
	// Write your code here.
}
