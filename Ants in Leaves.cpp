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
int n,cnt,maxi=-1,dep[iat];
vector <int> g[iat],store;
void dfs(int u, int par)
{
    dep[u]=dep[par]+1;
    if(g[u].size()==1)store.push_back(dep[u]);
    for(auto v : g[u])
    {
        if(v!=par)dfs(v,u);
    }
}
int main()
{
    fast_IO();
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(auto i : g[1])
    {
        store.clear();
        dfs(i,1);
        sort(store.begin(),store.end());
        for(int i=0; i<store.size(); i++)maxi=max(maxi,store[i]+int(store.size())-i-1);
    }
    cout<<maxi;
}

