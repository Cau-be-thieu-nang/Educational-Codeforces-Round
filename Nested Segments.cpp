#include <bits/stdc++.h>
#define iat 1000009
#define ll long long
#define LOG 20
#define MASK(i) (1LL << (i)) // 2 luy thua i
#define BIT(x,i) (((x) >> (i)) & 1) // lay ra bit thu i cua so x
using namespace std;
const ll INF=LLONG_MAX;
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
int n,tree[iat],d[iat],cnt;
struct mang
{
    int l,r,pos;
}a[iat];
bool cmp(mang x, mang y)
{
    return x.l>y.l;
}
void update(int k)
{
    while(k<=n)tree[k]++,k+=k&-k;
}
int getans(int k)
{
    int ans=0;
    while(k>0)ans+=tree[k],k-=k&-k;
    return ans;
}
signed main()
{
    fast_IO();
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i].l>>a[i].r,a[i].pos=i,d[++cnt]=a[i].r;
    sort(d+1,d+cnt+1);
    cnt=unique(d+1,d+cnt+1)-d-1;
    sort(a+1,a+n+1,cmp);
    int ans[n+1];
    for(int i=1; i<=n; i++)
    {
        a[i].r=lower_bound(d+1,d+cnt+1,a[i].r)-d;
        ans[a[i].pos]=getans(a[i].r);
        update(a[i].r);
    }
    for(int i=1; i<=n; i++)cout<<ans[i]<<'\n';
}

