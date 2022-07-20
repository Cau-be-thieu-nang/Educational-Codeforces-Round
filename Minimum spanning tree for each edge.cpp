#include <bits/stdc++.h>
#define iat 200009
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
int n,m,p[iat],dep[iat],f[iat][LOG],maxi[iat][LOG];
ll d;
bool check[iat];
struct edge
{
    int u,v,w,pos;
};
vector <pair<int,int>> gg[iat];
vector <edge> g;
void make_set()
{
    for(int i=1; i<=n; i++)p[i]=-1;
}
int find_set(int i)
{
    while(p[i]>0)i=p[i];
    return i;
}
bool Union(int i, int j)
{
    int u=find_set(i),v=find_set(j);
    if(u==v)return false;
    else if(u>v)p[u]+=p[v],p[v]=u;
    else p[v]+=p[u],p[u]=v;
    return true;
}
bool cmp(edge x, edge y)
{
    return x.w<y.w;
}
bool cmp1(edge x, edge y)
{
    return x.pos<y.pos;
}
void kruskal()
{
    vector <edge> mst;
    sort(g.begin(),g.end(),cmp);
    for(int i=0; i<m; i++)
    {
        if(mst.size()==n-1)break;
        edge e=g[i];
        if(Union(e.u,e.v))
        {
            check[e.pos]=true;
            mst.push_back(e);
            d+=e.w;
            gg[e.u].push_back({e.v,e.w});
            gg[e.v].push_back({e.u,e.w});
        }
    }
}
void dfs(int now, int par, int trongso)
{
    dep[now]=dep[par]+1;
    f[now][0]=par;
    maxi[now][0]=trongso;
    for(int i=1; (1<<i)<=dep[now]; i++)
    {
        f[now][i]=f[f[now][i-1]][i-1];
        maxi[now][i]=max(maxi[now][i-1],maxi[f[now][i-1]][i-1]);
    }
    for(auto next : gg[now])
    {
        if(next.first!=par)dfs(next.first,now,next.second);
    }
}
int LCA(int a, int b)
{
    int ans=0;
    if(a==b)return a;
    if(dep[a]<dep[b])swap(a,b);
    int k=dep[a]-dep[b];
    for(int i=LOG-1; i>=0; i--)
    {
        if(k&(1<<i))a=f[a][i];
    }
    if(a==b)return a;
    for(int i=LOG-1; i>=0; i--)
    {
        if(f[a][i]!=f[b][i])
        {
            a=f[a][i];
            b=f[b][i];
        }
    }
    return f[a][0];
}
int find_max(int x, int y)
{
    int s=0;
    for(int i=LOG-1; i>=0; i--)
    {
        if(dep[f[x][i]]>=dep[y])
        {
            s=max(s,maxi[x][i]);
            x=f[x][i];
        }
    }
    return s;
}
int main()
{
    fast_IO();
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        edge e;
        cin>>e.u>>e.v>>e.w;
        e.pos=i;
        g.push_back(e);
    }
    make_set();
    kruskal();
    dfs(1,0,0);
    sort(g.begin(),g.end(),cmp1);
    for(int i=0; i<m; i++)
    {
        if(check[g[i].pos])cout<<d<<'\n';
        else
        {
            int x=g[i].u,y=g[i].v,z=LCA(x,y);
            cout<<d+g[i].w-max(find_max(x,z),find_max(y,z))<<'\n';
        }
    }
}
