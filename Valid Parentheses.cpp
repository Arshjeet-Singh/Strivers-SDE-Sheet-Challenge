bool isValidParenthesis(string exp)
{
    stack<char> s;
    int n=exp.size();
    for(int i=0;i<n;i++)
    {
        if(s.empty() || exp[i]=='{' || exp[i]=='[' || exp[i]=='(')
        {
            s.push(exp[i]);
        } 
        else 
        {
          if (exp[i] == '}' ) 
          {
              if(s.top() == '{')
              {
                s.pop();
              }
              else
              {
                  s.push(exp[i]);
              }
          }
          else if (exp[i] == ')') 
          {
            if(s.top() == '(')
              {
                s.pop();
              }
              else
              {
                  s.push(exp[i]);
              }
          }
          else if (exp[i] == ']') 
          {
            if(s.top() == '[')
              {
                s.pop();
              }
              else
              {
                  s.push(exp[i]);
              }
          }
        }
    }
    if(s.empty())
    {
        return true;
    }
    return false;
    // Write your code here.
}
