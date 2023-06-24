int bs(int* arr, int l,int h, int key)
{
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return -1;
}
int search(int* arr, int n, int key) {
    int l=0,h=n-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        if(arr[l]<=arr[mid])
        {
            if(arr[l]<=key && key<=arr[mid])
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        else
        {
            if(arr[mid]<=key && key<=arr[h])
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
    }
    // int ind=0;
    // for(int i=0;i<n;i++)
    // {
    //     if(arr[i]==key)
    //     {
    //         return i;
    //     }
    //     if(i!=n-1 && arr[i]>arr[i+1])
    //     {
    //         ind=i;
    //         break;
    //     }
    // }
    // int a=bs(arr,0,ind,key);
    // if(a!=-1)
    // {
    //     return a;
    // }
    // int b=bs(arr,ind+1,n,key);
    // if(b!=-1)
    // {
    //     return b;
    // }
    return -1;
    // Write your code here.
}
