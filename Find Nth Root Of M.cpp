#include<bits/stdc++.h>
int f(int m,int mid,int n)
{
  long long ans=1;
  for(int i=1;i<=n;i++)
  {
    ans=ans*mid;
    if(ans>m)
    {
      return 2;
    }
  }
  if(ans==m)
    {
      return 1;
    }
  return 0;
}
int NthRoot(int n, int m) {
  int l=1,h=m;
  while(l<=h)
  {
    int mid=(l+h)/2;
    int midn=f(m,mid,n);
    if(midn==1)
    {
      return mid;
    }
    else if(midn==2)
    {
      h=mid-1;
    }
    else
    {
      l=mid+1;
    }
  }
  return -1;
  // Write your code here.
}
