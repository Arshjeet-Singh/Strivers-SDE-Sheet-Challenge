#include<bits/stdc++.h>
 vector<int> ns(vector < int > & a)
 {
   stack<int> s;
   s.push(-1);
   int n=a.size();
   vector<int> ans(n);
   for(int i=n-1;i>=0;i--)
   {
    //  if(s.top()!=-1 && a[s.top()]<a[i])
    //  {
    //    ans.push_back(s.top());
    //    s.push(i);
    //  }
    //  else
    //  {
       while(s.top()!=-1 && a[s.top()]>=a[i])
       {
         s.pop();
       }
       ans[i]=s.top();
       s.push(i);
     }
   return ans;
 }
 vector<int> ps(vector < int > & a)
 {
   stack<int> s;
   s.push(-1);
   int n=a.size();
   vector<int> ans(n);
   for(int i=0;i<n;i++)
   {
       while(s.top()!=-1 && a[s.top()]>=a[i])
       {
         s.pop();
       }
       ans[i]=s.top();
       s.push(i);
     }
   return ans;
 }
 int largestRectangle(vector < int > & heights) {
   int n=heights.size();
   vector<int> next=ns(heights);
   vector<int> prev=ps(heights);
   int ar=0;
  //  int n=heights.size();
   for(int i=0;i<n;i++)
   {

     if(next[i]==-1)
     {
       next[i]=n;
     }
     int l=heights[i];
     int b=next[i]-prev[i]-1;
     ar=max(ar,l*b); 
   }
   return ar;
   // Write your code here.
 }
