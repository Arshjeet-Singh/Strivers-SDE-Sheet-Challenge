#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int n, int m, int k) {
      if (n > m)
    return ninjaAndLadoos(row2, row1, m, n, k);

  int low = max(0, k - m), high = min(n, k); // cannot take all elements 
  while (low <= high) {
    int cut1 = (low + high) >> 1;
    int cut2 = k - cut1;

    int l1 = cut1 == 0 ? INT_MIN : row1[cut1 - 1];
    int l2 = cut2 == 0 ? INT_MIN : row2[cut2 - 1];
    int r1 = cut1 == n ? INT_MAX : row1[cut1];
    int r2 = cut2 == m ? INT_MAX : row2[cut2];

    if (l1 <= r2 and l2 <= r1)
      return max(l1, l2);
    else if (l1 > r2)
      high = cut1 - 1;
    else
      low = cut1 + 1;
  }

  return 1;
    // if(n>m)
    // {
    //     return (row2,row1,m,n,k);
    // }
    // int l=max(0,k-m),h=min(n,k);
    // while(l<=h)
    // {
    //     int cut1=(l+h)/2;
    //     int cut2=k-cut1;
    //     int l1=cut1==0?INT_MIN:row1[cut1-1];
    //     int l2=cut2==0?INT_MIN:row2[cut2-1];
    //     int r1=cut1==n?INT_MAX:row1[cut1];
    //     int r2=cut2==m?INT_MAX:row2[cut2];
    //     if(l1<=r2 && l2<=r1)
    //     {
    //         return max(l1,l2);
    //     }
    //     else if(l1>r2)
    //     {
    //         h=cut1-1;
    //     }
    //     else
    //     {
    //         l=cut1+1;
    //     } 
    // }
    // return 1;
    // int i=0,j=0,l=0;
    // while(i<n && j<n)
    // {
    //     if(row1[i]<=row2[j])
    //     {
    //         i++;
    //         l++;
    //         if(l==k)
    //         {
    //             return row1[i-1];
    //         }
    //     }
    //     else
    //     {
    //         j++; l++;
    //         if(l==k)
    //         {
    //             return row2[j-1];
    //         }
    //     }
    // }
    // while(i<n)
    // {
    //     i++;
    //         l++;
    //         if(l==k)
    //         {
    //             return row1[i-1];
    //         }       
    // }
    // while(j<n)
    // {
    //     j++;
    //     l++;
    //     if(l==k)
    //     {
    //         return row2[j-1];
    //     }       
    // }
    // return -1;
    // Write your code here.
}
