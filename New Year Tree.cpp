#include <bits/stdc++.h>
#define iat 2000009
#define ll long long
#define LOG 20
#define MASK(i) (1LL << (i)) // 2 luy thua i
#define BIT(x,i) (((x) >> (i)) & 1) // lay ra bit thu i cua so x
#define mid (l+r)/2
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
int n,m,c[iat],tin[iat],tout[iat],Time;
ll tree[iat],lazy[iat];
vector <int> g[iat];
void dfs(int u, int par)
{
    tin[u]=++Time;
    for(auto v : g[u])
    {
        if(v!=par)dfs(v,u);
    }
    tout[u]=Time;
}
void down(int id)
{
    if(lazy[id]!=0)
    {
        tree[2*id]=tree[2*id+1]=lazy[2*id]=lazy[2*id+1]=lazy[id];
        lazy[id]=0;
    }
}
void update(int id, int l, int r, int u, int v, ll val)
{
    if(l>v || r<u)return;
    if(u<=l && r<=v)
    {
        tree[id]=lazy[id]=val;
        return;
    }
    down(id);
    update(2*id,l,mid,u,v,val);
    update(2*id+1,mid+1,r,u,v,val);
    tree[id]=tree[2*id]|tree[2*id+1];
}
ll getans(int id, int l, int r, int u, int v)
{
    if(l>v || r<u)return 0;
    if(u<=l && r<=v)return tree[id];
    down(id);
    return getans(2*id,l,mid,u,v)|getans(2*id+1,mid+1,r,u,v);
}
void solve1()
{
    int v,cl;
    cin>>v>>cl;
    update(1,1,n,tin[v],tout[v],MASK(cl));
}
void solve2()
{
    int v;
    cin>>v;
    cout<<__builtin_popcountll(getans(1,1,n,tin[v],tout[v]))<<'\n';
}
int main()
{
    fast_IO();
    cin>>n>>m;
    for(int i=1; i<=n; i++)cin>>c[i];
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,-1);
    for(int i=1; i<=n; i++)update(1,1,n,tin[i],tin[i],MASK(c[i]));
    while(m--)
    {
        int t;
        cin>>t;
        if(t==1)solve1();
        else solve2();
    }
}
