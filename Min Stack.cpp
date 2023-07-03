#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<pair<int,int>> s;
	// int mini;
	public:
		
		// Constructor
		minStack() 
		{ 
			// mini=INT_MAx;
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			if(s.empty())
			{
				s.push({num,num});
			}
			else
			{
				if(num<s.top().second)
				{
					s.push({num,num});
				}
				else
				{
					s.push({num,s.top().second});
				}
			}
			// Write your code here.
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(s.empty())
			{
				return -1;
			}
			int ele=s.top().first;
			s.pop();
			return ele;
			// Write your code here.
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(s.empty())
			{
				return -1;
			}
			int ele=s.top().first;
			// s.pop();
			return ele;
			// Write your code here.
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(s.empty())
			{
				return -1;
			}
			int ele=s.top().second;
			// s.pop();
			return ele;
			// Write your code here.
		}
};
