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
int n,m,p[iat],pos[iat];
vector <int> a[iat];
signed main()
{
    fast_IO();
    cin>>n>>m;
    for(int i=1; i<=n; i++)cin>>p[i],pos[p[i]]=i;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        x=pos[x],y=pos[y];
        if(x>y)swap(x,y);
        a[x].push_back(y);
    }
    ll ans=0;
	int rg=n+1;
	for(int i=n; i>=1; i--)
    {
		for(int j=0; j<a[i].size(); j++)rg=min(rg,a[i][j]);
		ans+=rg-i;
	}
	cout<<ans;
}

