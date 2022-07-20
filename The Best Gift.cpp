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
int n,m,a[iat],b[11],ans,sum,tmp;
int main()
{
    fast_IO();
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1; i<11; i++)sum+=b[i];
    for(int i=1; i<11; i++)
    {
        tmp+=b[i];
        ans+=b[i]*(sum-tmp);
    }
    cout<<ans;
}

