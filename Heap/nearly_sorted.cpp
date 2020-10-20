#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int x, k;
    cin>>x>>k;

    priority_queue<pair<int, int> > mh;
    for(int i=0; i<n; i++)
    {
        mh.push(make_pair(abs(a[i]-x), a[i]));

        if(mh.size()>k)
        {
            mh.pop();
        }
    }

    while(mh.size()>0)
    {
        cout<<mh.top().second<<" ";
        mh.pop();
    }
}
