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
int n,m,a[iat],cnt[iat],b[iat],maxi=1;
int main()
{
    fast_IO();
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]<=m)cnt[a[i]]++;
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=m && i*j*1LL<=m; j++)b[i*j]+=cnt[i];
    }
    for(int i=1; i<=m; i++)
    {
        if(b[i]>b[maxi])maxi=i;
    }
    cout<<maxi<<" "<<b[maxi]<<'\n';
    for(int i=1; i<=n; i++)
    {
        if(a[i]<=m && maxi%a[i]==0)cout<<i<<" ";
    }
}

