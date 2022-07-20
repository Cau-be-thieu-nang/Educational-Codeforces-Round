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
int n,m[iat];
ll sum,cnt,mod,ans;
int main()
{
    fast_IO();
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>m[i];
        sum+=m[i];
    }
    cnt=sum/n;
    mod=sum%n;
	sort(m+1,m+n+1);
	for(int i=1; i<=n-mod; i++)ans+=abs(m[i]-cnt);
	for(int i=n-mod+1; i<=n; i++)ans+=abs(m[i]-cnt-1);
	ans/=2;
	cout<<ans<<endl;
}

