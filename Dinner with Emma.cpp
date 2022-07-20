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
int n,m,c[101][101],maxi[101];
int main()
{
    fast_IO();
    cin>>n>>m;
    for(int i=1; i<=n; i++)maxi[i]=INT_MAX;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>c[i][j];
            maxi[i]=min(maxi[i],c[i][j]);
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++)ans=max(ans,maxi[i]);
    cout<<ans;
}

