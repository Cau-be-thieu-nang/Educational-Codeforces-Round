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
int m,l,r,k;
string s;
int main()
{
    fast_IO();
    cin>>s>>m;
    s=" "+s;
    while(m--)
    {
        cin>>l>>r>>k;
        k=k%(r-l+1);
        if(k==0)continue;
        string tmp="";
        for(int i=r-k+1; i<=r; i++)tmp+=s[i];
        for(int i=l; i<r-k+1; i++)tmp+=s[i];
        for(int i=l; i<=r; i++)s[i]=tmp[i-l];
    }
    for(int i=1; i<s.size(); i++)cout<<s[i];
}
