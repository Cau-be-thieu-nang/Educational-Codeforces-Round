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
ll n;
int main()
{
    fast_IO();
    cin>>n;
    ll i=1,cnt=1,tmp;
    while(cnt<=n)i++,cnt+=i;
    tmp=cnt-i;
    if(tmp==n)cout<<i-1;
    else cout<<n-tmp;
}

