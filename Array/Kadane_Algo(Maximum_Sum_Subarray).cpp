int maxSubArray(vector<int> &A) {
    int maxx_so_far=INT_MIN;
    int maxx_end_here=0;
    for(int i=0;i<A.size();i++)
    {  maxx_end_here+= A[i];
       maxx_so_far=max(maxx_so_far,maxx_end_here);
       if(maxx_end_here<0)
       maxx_end_here=0;
    }
    return maxx_so_far;

}