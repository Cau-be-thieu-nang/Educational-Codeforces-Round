#include <bits/stdc++.h>
#define iat 100009
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
ll n,c[iat],w[iat],sz[iat],cnt[iat];
ll sum[iat];
vector <int> g[iat];
map <ll,ll> m[iat];
void Union(int x, int y)
{
    if(m[w[x]].size()<m[w[y]].size())swap(w[x],w[y]);
    for(auto it=m[w[y]].begin(); it!=m[w[y]].end(); it++)
    {
        ll mau=it->first,val=it->second;
        m[w[x]][mau]+=val;
        if(m[w[x]][mau]>sz[w[x]])
        {
            sz[w[x]]=m[w[x]][mau];
            cnt[w[x]]=0;
        }
        if(m[w[x]][mau]==sz[w[x]])cnt[w[x]]+=mau;
    }
}
void dfs(int u, int par)
{
    for(auto v : g[u])
    {
        if(v!=par)dfs(v,u),Union(u,v);
    }
    sum[u]=cnt[w[u]];
}
int main()
{
    fast_IO();
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>c[i];
        w[i]=i;
        cnt[i]=c[i];
        sz[i]=1;
        m[i][c[i]]=1;
    }
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1; i<=n; i++)cout<<sum[i]<<" ";
}

