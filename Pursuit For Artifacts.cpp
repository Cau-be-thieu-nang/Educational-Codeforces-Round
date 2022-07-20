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
int n,m,a,b,w[iat],v[iat][2];
vector <int> e[iat];
vector <pair<int,int>> v2[iat];
int low[iat],num[iat],t[iat],br[iat];
queue <int> q;
int good[iat],t2[iat];
void dfs(int x, int le)
{
    static int top=0;
    low[x]=num[x]=++top;
    for(auto i : e[x])
    {
        if(i!=le)
        {
            int y=v[i][0]+v[i][1]-x;
            if(!num[y])
            {
                t[y]=i;
                dfs(y,i);
            }
            low[x]=min(low[x],low[y]);
        }
    }
}
void bfs(int st)
{
    static int n1=0;
    num[st]=++n1;
    q.push(st);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto i : e[x])
        {
            if(!br[i])
            {
                int y=v[i][0]+v[i][1]-x;
                if(w[i])good[n1]=1;
                if(!num[y])
                {
                    num[y]=n1;
                    q.push(y);
                }
            }
        }
    }
}
int solve()
{
    dfs(a,0);
    for(int i=1; i<=n; i++)
    {
        if(low[i]>=num[i])br[t[i]]=1;
    }
    memset(num,0,sizeof(num));
    for(int i=1; i<=n; i++)
    {
        if(!num[i])bfs(i);
    }
    for(int i=1; i<=m; i++)
    {
        if(br[i])
        {
            int x=num[v[i][0]],y=num[v[i][1]];
            v2[x].push_back({y,w[i]});
            v2[y].push_back({x,w[i]});
        }
    }
    a=num[a],b=num[b];
    q.push(a);
    memset(t2,-1,sizeof(t2));
    t2[a]=good[a];
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto i : v2[x])
        {
            if(t2[i.first]==-1)
            {
                t2[i.first]=t2[x]|i.second|good[i.first];
                q.push(i.first);
            }
        }
    }
    return t2[b];
}
signed main()
{
    fast_IO();
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y>>w[i];
        e[x].push_back(i);
        e[y].push_back(i);
        v[i][0]=x;
        v[i][1]=y;
    }
    cin>>a>>b;
    if(solve())cout<<"YES";
    else cout<<"NO";
}

