vector<int> Solution::plusOne(vector<int> &A) {
    int e=A.size()-1;
    int carry=0;
    int sum=0;
    vector<int>res;
    bool flag=true;
    while(e>=0 || carry )
    {  
         sum=carry;
          if(e>=0)
          sum+=A[e];
          if(flag)
          sum+=1;
         
         
          flag=false;
          carry=sum/10;
          sum=sum%10;
          res.push_back(sum);
          e--;


    }
  
    e=res.size()-1;

    while(e>=0)
    { if(res[e]==0)
       {
           res.pop_back();
       }
       else break;
       e--;

    }
    reverse(res.begin(),res.end());
    return res;
}
