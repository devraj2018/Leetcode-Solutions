int Solution::canJump(vector<int> &A) {
    int maxreachable=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {  if(i>maxreachable)
           return 0;
          maxreachable=max(maxreachable,i+A[i]);
         

    }
    return 1;
}
