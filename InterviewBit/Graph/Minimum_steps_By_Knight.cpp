struct node{
    int x,y,t;
    node(int _x, int _y, int _t)
    {
        x= _x;
        y= _y;
        t= _t;
    }
};
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<bool>>dp(A+1,vector<bool>(B+1,false));
    int res=0;
    queue<node> q;
    q.push(node(C,D,0));
    int dx[8]={-2,-2,2,2,-1,-1,1,1};
    int dy[8]={1,-1,1,-1,2,-2,2,-2};
    dp[C][D]=true;
    while(!q.empty())
    { int x=q.front().x;
      int y=q.front().y;
      int t=q.front().t;
      q.pop();
      res=max(res,t);
      if(x==E && y==F)
       return t;
      for(int i=0;i<8;i++)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=1 && newy>=1 && newx<=A && newy<=B && dp[newx][newy]==false)
            { dp[newx][newy]=true;
              q.push(node(newx,newy,t+1));
            }

        }
    }
    return -1;

}