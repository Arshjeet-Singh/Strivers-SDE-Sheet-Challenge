string kthPermutation(int n, int k) {
    int fact=1;
    vector<int> v;
    string ans="";
    for(int i=1;i<n;i++)
    {
        fact=fact*i;
        v.push_back(i);
    }
    v.push_back(n);
    k=k-1;
    while(1)
    {
        ans+=to_string(v[k/fact]);
        v.erase(v.begin()+k/fact);
        if(v.size()==0)
        {
            return ans;
        }
        k=k%fact;
        fact=fact/v.size();
    }
    return ans;
    // Write your code here.
}
