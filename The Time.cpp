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
string s;
int a;
ll xau_to_so(string s)
{
    ll x=0;
    for(int i=0; i<s.length(); i++)
    {
        int y=int(s[i])-48;
        x=x*10+y;
    }
    return x;
}
int main()
{
    fast_IO();
    cin>>s>>a;
    int h=xau_to_so(s.substr(0,2))+a/60,m=xau_to_so(s.substr(3,2))+a%60;
    if(m>=60)m-=60,h++;
    if(h>=24)h%=24;
    if(h/10!=0)cout<<h;
    else cout<<0<<h;
    cout<<':';
    if(m/10!=0)cout<<m;
    else cout<<0<<m;
}

