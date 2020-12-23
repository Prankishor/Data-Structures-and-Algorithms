#include<bits/stdc++.h>
using namespace std;
int  x()
{
return 0;
}
int reee(int n)
{
  for(int i=n;i>0;i--)
  {
  if(i==2)
  {
    return x();
  }
  else if(n==1)
  {
    return 6;
  }
  else
  {
     return reee(i-1)+1;
  }
}
}
int main()
{
  cout<<reee(5)<<" ";
}
