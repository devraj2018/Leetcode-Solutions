class Solution {
public:
    bool isOperator(string x)
    {
         if(x=="+" || x=="/" || x=="*" || x=="-")
             return true;
        return false;
     }
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> s;
        for(int i=0;i<n;i++)
           {  string x=tokens[i];
                if(!isOperator(x))
                    {s.push(stoi(x));
                       continue;
                    }
                int b= s.top();
                  s.pop();
                int a=s.top();
                  s.pop();
                if(x=="+") s.push(a+b);
                else if(x=="-") s.push(a-b);
                else if(x=="*") s.push(a*b);
                else s.push(a/b);    
         }
        return s.top();  
    }
};