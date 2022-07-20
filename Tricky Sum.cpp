#include <bits/stdc++.h>
#define iat 1000009
#define ll long long
#define LOG 30
using namespace std;
void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if(fopen("t.inp","r"))
    {
        freopen("t.inp","r",stdin);
        freopen("t.out","w",stdout);
    }
}
ll t,n;
ll twopow(int x)
{
    ll res=1;
    for(int i=1; i<=x; i++)res*=2;
    return res;
}
int main()
{
    fast_IO();
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll sum=0;
        for(int i=0; twopow(i)<=n; i++)sum-=2*twopow(i);
        sum+=((n+1)*n)/2;
        cout<<sum<<'\n';
    }
}
