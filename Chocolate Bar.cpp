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
int t,n,m,k,dp[31][31][51];
int f(int x, int y, int z)
{
    if(dp[x][y][z] || x*y==z || !z)return dp[x][y][z];
    int mini=1e9;
    for(int i=1; i<=x-i; i++)
    {
        for(int j=0; j<=k; j++)
        {
            mini=min(mini,y*y+f(i,y,k-j)+f(x-i,y,j));
        }
    }
    for(int i=1; i<=y-i; i++)
    {
        for(int j=0; j<=k; j++)
        {
            mini=min(mini,x*x+f(x,i,k-j)+f(x,y-i,j));
        }
    }
    return dp[x][y][z]=mini;
}
int main()
{
    fast_IO();
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cout<<f(n,m,k)<<'\n';
    }
}
