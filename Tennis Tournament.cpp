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
int n,b,p,ans;
int main()
{
    fast_IO();
    cin>>n>>b>>p;
    int ans1=n*p;
    while(n>1)
    {
        if(n%2==0)ans+=n*b+n/2,n/=2;
        else ans+=(n-1)*b+n/2,n/=2,n++;
    }
    cout<<ans<<" "<<ans1;
}

