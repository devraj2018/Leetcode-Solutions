int Solution::perfectPeak(vector<int> &A) {
    int e=A.size()-1;
    int i=0;
    vector<int> Left(e+1);
    vector<int> Right(e+1);
    Left[0]=A[0];
    Right[e]=A[e];
    for(int i=1;i<=e;i++)
      Left[i]=max(Left[i-1],A[i-1]);
    for(int i=e-1;i>=0;i--)
      Right[i]=min(Right[i+1],A[i+1]);
    for(int i=1;i<=e;i++)
       if(A[i]> Left[i] && A[i]<Right[i])
           return 1;
return 0;
}
