int Solution::maxProfit(const vector<int> &A) {

    int maxx=0;
    for(int i=1;i<A.size();i++)
    {
         if(A[i]>A[i-1])
          maxx+=A[i]-A[i-1];

    }
    return maxx;
}
