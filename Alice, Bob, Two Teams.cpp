#include <bits/stdc++.h>
#define iat 1000009
#define ll long long
#define LOG 20
#define MASK(i) (1LL << (i)) // 2 luy thua i
#define BIT(x,i) (((x) >> (i)) & 1) // lay ra bit thu i cua so x
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
int n,p[iat];
string s;
ll ans,maxi;
int main()
{
    fast_IO();
    cin>>n;
    for(int i=1; i<=n; i++)cin>>p[i];
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='B')ans+=p[i+1];
    }
    ll tmp=ans;
    maxi=ans;
    for(int i=1; i<=n; i++)
    {
        if(s[i-1]=='A')tmp+=p[i];
        else tmp-=p[i];
        maxi=max(maxi,tmp);
    }
    tmp=ans;
    for(int i=n; i>=1; i--)
    {
        if(s[i-1]=='A')tmp+=p[i];
        else tmp-=p[i];
        maxi=max(maxi,tmp);
    }
    cout<<maxi;
}

