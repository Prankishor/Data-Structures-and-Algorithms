#include<bits/stdc++.h>
using namespace std;


//(1)   LET X be the missing number and Y be the repeating number

//(2)   n(n+1)/2 - sum of given elements  = (x-y) ------>equation(1)

//(3)   n(n+1)(2n+1)/6 - sum of square of given elements = x^2 - y^2
//      which is also equals to (x-1)(x+1) ---->equation(2) 

//(4)   replace the value of x-1 in equation(2)

//(5)   you will get value of x+y

//(6)   solve (x+y) + (x-y), will get 2x = something;

//(7)   find x and then put x in one equation (lets say x+y) and find y

//       NOTE: USE LONG INT TO CALCULATE SUM OF SQUARE OF THE NUMBERS

int main()
{
	int n = 6;
	int ar[n] = {4,3,6,2,1,1};
	
	int sum = 0;
	long int sumSqr = 0;
	int x, y;
	
	for(int i=0; i<n; i++)
	{
		sum+=ar[i];
		sumSqr+= ar[i]*ar[i];
	}
	
	//cout<<sum<<" "<<sumSqr<<endl;
	int tol = 0, upor = 0;
	
	tol = abs(((n*(n+1))/2) - sum);
	upor = abs(((n*(n+1)*(2*n+1))/6) - sumSqr);
	
	//cout<<tol<<" "<<upor<<endl;
	
	//x+y
	int preAns = upor/tol;
	
	cout<<"Missing number is : "<<(preAns + tol)/2<<endl;
	cout<<"Repeating number is : "<<abs((preAns+tol)/2-preAns)<<endl;
}
	

