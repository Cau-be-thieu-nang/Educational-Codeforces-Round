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
int n,m,c[1001][1001],cnt,ans[1001][1001];
char a[1001][1001];
set <pair<int,int>> se;
bool check(int i, int j)
{
    if(i<1 || i>n || j<1 || j>m)return false;
    if(a[i][j]=='.')
    {
        if(!c[i][j])return true;
        return false;
    }
    else
    {
        se.insert({i,j});
        return false;
    }
}
void dfs(int i, int j)
{
    cnt++;
    c[i][j]=true;
    if(check(i-1,j))dfs(i-1,j);
    if(check(i+1,j))dfs(i+1,j);
    if(check(i,j-1))dfs(i,j-1);
    if(check(i,j+1))dfs(i,j+1);
}
int main()
{
    fast_IO();
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)cin>>a[i][j];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]=='.' && !c[i][j])
            {
                se.clear();
                cnt=0;
                dfs(i,j);
                for(auto it : se)ans[it.first][it.second]+=cnt;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]=='.')cout<<'.';
            else cout<<(ans[i][j]+1)%10;
        }
        cout<<'\n';
    }
}

