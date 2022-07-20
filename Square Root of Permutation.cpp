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
int n,p[iat],length,ans[iat];
bool visited[iat];
vector <int> g[iat];
void dfs(int u)
{
    visited[u]=true;
    cout<<length<<" "<<u<<'\n';
    g[length].push_back(u);
    if(!visited[p[u]])dfs(p[u]);
}
bool cmp(vector <int> a, vector <int> b)
{
    return a.size()<b.size();
}
int main()
{
    fast_IO();
    cin>>n;
    for(int i=1; i<=n; i++)cin>>p[i];
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])length++,dfs(i);
    }
    sort(g+1,g+length+1,cmp);
    for(int i=1; i<=length; i++)
    {
        if(g[i].size()%2!=0)
        {
            int mid=g[i].size()/2;
            mid++;
            for(int j=0; j<g[i].size(); j++)ans[g[i][j]]=g[i][(j+mid)%g[i].size()];
        }
        else
        {
            if(g[i].size()!=g[i+1].size())
            {
                cout<<-1;
                return 0;
            }
            for(int j=0; j<g[i].size(); j++)
            {
                ans[g[i][j]]=g[i+1][j];
                ans[g[i+1][j]]=g[i][(j+1)%g[i].size()];
            }
            i++;
        }
    }
    for(int i=1; i<=n; i++)cout<<ans[i]<<" ";
}

