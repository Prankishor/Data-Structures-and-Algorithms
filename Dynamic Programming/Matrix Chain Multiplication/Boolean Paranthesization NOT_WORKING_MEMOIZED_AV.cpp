//Dynamic Programming
//Problem: Boolean Paranthesization

#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;
//Recursion
int solve(string exp, int i, int j, bool tf)
{
	//base condition
	if(i>j)
	{
		return true;
	}
	
	if(i==j)
	{
		if(tf == true)
	    {
	    	return exp[i]=='T';
	    }
    	else
	    {
	    	return exp[i]=='F';
	    }
	
    }
    
	int ans = 0;
	
	//k loop
	for(int k=i+1; k<=j-1; k+2)
	{
		//lt = left true, rt= right true, lf= left false, rf = right false
		int lt=solve(exp, i, k-1, true);
		int lf=solve(exp, i, k-1, false);
		int rt=solve(exp, k+1, j, true);
		int rf=solve(exp, k+1, j, false);
		
		if(exp[k]=='&')
		{
			if(tf==true)
			{
				ans=ans+lt*rt;
			}
			else
			{
				ans=ans+lf*rt+lt*rf+lf*rf;
			}
		}
		else if(exp[k]=='|')
		{
			if(tf==true)
			{
				ans=ans+lt*rt+lt*rf+lf*rt;
			}
			else
			{
				ans=ans+lf*rf;
			}
		}
		else if(exp[k]=='^')
		{
			if(tf==true)
			{
				ans=ans+lf*rt+lt*rf;

			}
			else
			{
				ans=ans+lt*rt+lf*rf; 
			}
		}
		
	}
	return ans;
}

//Memoization

int solveM(string exp, int i, int j, bool tf)
{
		//base condition
	if(i>j)
	{
		return true;
	}
	
	if(i==j)
	{
		if(tf == true)
	    {
	    	return exp[i]=='T';
	    }
    	else
	    {
	    	return exp[i]=='F';
	    }
	
    }
    
    //change (key of map = temp)
    string temp=to_string(i);
    temp.push_back(" ");
    temp.append(to_string(j));
    temp.push_back(" ");
    temp.append(to_string(tf));
    
    if(m.find(temp)!=m.end())
    {
    	return m[temp];
	}
    
    int ans = 0;
	
	//k loop
	for(int k=i+1; k<=j-1; k+2)
	{
		//lt = left true, rt= right true, lf= left false, rf = right false
		int lt=solve(exp, i, k-1, true);
		int lf=solve(exp, i, k-1, false);
		int rt=solve(exp, k+1, j, true);
		int rf=solve(exp, k+1, j, false);
		
		if(exp[k]=='&')
		{
			if(tf==true)
			{
				ans=ans+lt*rt;
			}
			else
			{
				ans=ans+lf*rt+lt*rf+lf*rf;
			}
		}
		else if(exp[k]=='|')
		{
			if(tf==true)
			{
				ans=ans+lt*rt+lt*rf+lf*rt;
			}
			else
			{
				ans=ans+lf*rf;
			}
		}
		else if(exp[k]=='^')
		{
			if(tf==true)
			{
				ans=ans+lf*rt+lt*rf;

			}
			else
			{
				ans=ans+lt*rt+lf*rf; 
			}
		}
		
	}
	//change
	return m[temp]=ans;
}
int main()
{
	string exp;
	cin>>exp;
	m.clear();
	int i = 0;
	int j = exp.size()-1;
	int ans = solveM(exp, i, j, true);
	cout<<ans<<endl;
}
