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
int n,m,k,s,mina[iat],minb[iat],a[iat],b[iat],posa[iat],posb[iat];
struct mang
{
    int t,c,pos;
    ll mul;
};
mang tai[iat];
bool cmp(mang x, mang y)
{
    return x.mul<y.mul;
}
bool check(int x)
{
    for(int i=1; i<=m; i++)
    {
        if(tai[i].t==1)tai[i].mul=1LL*tai[i].c*mina[x];
        else tai[i].mul=1LL*tai[i].c*minb[x];
    }
    sort(tai+1,tai+m+1,cmp);
    ll cnt=0;
    for(int i=1; i<=m; i++)
    {
        if(cnt+tai[i].mul>s)
        {
            if(i-1<k)return false;
            return true;
        }
        cnt+=tai[i].mul;
    }
    return true;
}
int main()
{
    fast_IO();
    cin>>n>>m>>k>>s;
    mina[0]=INT_MAX,minb[0]=INT_MAX;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(mina[i-1]>a[i])posa[i]=i;
        else posa[i]=posa[i-1];
        mina[i]=min(mina[i-1],a[i]);
    }
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
        if(minb[i-1]>b[i])posb[i]=i;
        else posb[i]=posb[i-1];
        minb[i]=min(minb[i-1],b[i]);
    }
    for(int i=1; i<=m; i++)
    {
        cin>>tai[i].t>>tai[i].c;
        tai[i].pos=i;
    }
    int l=1,r=n,mid,ans=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<'\n';
    if(ans!=-1)
    {
        for(int i=1; i<=m; i++)
        {
            if(tai[i].t==1)tai[i].mul=1LL*tai[i].c*mina[ans];
            else tai[i].mul=1LL*tai[i].c*minb[ans];
        }
        sort(tai+1,tai+m+1,cmp);
        for(int i=1; i<=k; i++)
        {
            if(tai[i].t==1)cout<<tai[i].pos<<" "<<posa[ans]<<'\n';
            else cout<<tai[i].pos<<" "<<posb[ans]<<'\n';
        }
    }
}

