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
int n,k,a[iat],cnt[iat],cntk,l=1,xl,xr=-1;
int main()
{
    fast_IO();
    cin>>n>>k;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int r=1; r<=n; r++)
    {
        cnt[a[r]]++;
        if(cnt[a[r]]==1)cntk++;
        while(cntk>k)
        {
            cnt[a[l]]--;
            if(cnt[a[l]]==0)cntk--;
            l++;
        }
        if(r-l+1>xr-xl+1)xr=r,xl=l;
    }
    cout<<xl<<" "<<xr;
}

