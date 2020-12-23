#include<bits/stdc++.h>
using namespace std;
int  x()
{

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
    return 12;
  }
  else
  {
     return reee(i-1);
  }
}
}
int main()
{
  cout<<reee(5)<<" ";
}
