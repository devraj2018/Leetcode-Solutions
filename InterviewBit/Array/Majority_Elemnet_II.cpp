//        Boyer's Moore Algo  O(n)time + O(1)space //
int Solution::repeatedNumber(const vector<int> &A) {
  
 int n=A.size();
 int x=n/3;
 int num1=INT_MAX,num2=INT_MAX;
 int c1=0,c2=0;

 for(int i=0;i<n;i++)
 {
      if(A[i]==num1)
       c1++;
    else if(A[i]==num2)
    c2++;
    else if(c1==0)
    {
        num1=A[i];
        c1++;

    }
    else if(c2==0)
    {
        num2=A[i];
        c2++;
    }
    else
    {
        c1--;c2--;
    }
    
 }
 c1=0,c2=0;
 for(int i=0;i<n;i++)
 {  if(A[i]==num1)
      c1++;
    if(A[i]==num2)
    c2++;

 }
 if(c1>n/3)
 return num1;
 if(c2>n/3)
 return num2;


return -1;


}
