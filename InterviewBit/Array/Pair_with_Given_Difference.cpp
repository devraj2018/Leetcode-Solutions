int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int>mp;
    int n=A.size();
    for(int i=0;i<n;i++)
    { if(mp.find(A[i]-B)!=mp.end() ||mp.find(A[i]+B)!=mp.end())
         return 1;
      mp[A[i]]++;
        
    }
    return 0;
}
