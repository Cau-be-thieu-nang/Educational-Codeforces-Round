#include <bits/stdc++.h>
#define iat 1000009
#define ll long long
#define LOG 30
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
int n,m,k,hang[4]={0,-1,0,1},cot[4]={-1,0,1,0},luu[1001][1001];
pair <int,int> store[1001][1001];
bool visited[1001][1001];
char a[1001][1001];
void bfs(int x, int y)
{
    int cnt=0;
    queue <pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=true;
    while(!q.empty())
    {
        int x1=q.front().first,y1=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int u=x1+hang[i];
            int v=y1+cot[i];
            if(u>n || u<1)continue;
            if(v>m || v<1)continue;
            if(a[u][v]=='*')cnt++;
            else if(!visited[u][v])
            {
                store[u][v].first=x,store[u][v].second=y;
                visited[u][v]=true;
                q.push({u,v});
            }
        }
    }
    luu[x][y]=cnt;
    cout<<cnt<<'\n';
}
int main()
{
    fast_IO();
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)cin>>a[i][j];
    }
    while(k--)
    {
        int x,y;
        cin>>x>>y;
        if(luu[x][y])cout<<luu[x][y]<<'\n';
        else if(store[x][y].first)cout<<luu[store[x][y].first][store[x][y].second]<<'\n';
        else bfs(x,y);
    }
}
