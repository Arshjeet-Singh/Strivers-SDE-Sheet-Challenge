#include <bits/stdc++.h> 
void insertsorted(stack<int> &stack,int e)
{
	if(stack.empty() || stack.top()<e)
	{
		stack.push(e);
		return;
	}
	int n=stack.top();
	stack.pop();
	insertsorted(stack, e);
	stack.push(n);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty())
	{
		return;
	}
	int e=stack.top();
	stack.pop();
	sortStack(stack);
	insertsorted(stack,e);
	// if(s.top()<e)
	// {
	// 	sortStack(stack);
	// 	stack.push(e);
	// }
	// else
	// {
	// 	int e2=s.top();

	// }
	// Write your code here
}
