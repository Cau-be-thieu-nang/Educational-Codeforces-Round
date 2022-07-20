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
int n,ans[iat];
int main()
{
    fast_IO();
    cin>>n;
    for(int i=0; i<2*n; i++)ans[i]=n;
    for(int i=1; i<=n; i++)
    {
        int x;
        if(i&1)x=i>>1;
        else x=n-1+(i>>1);
        int y=x+n-i;
        ans[x]=ans[y]=i;
    }
    for(int i=0; i<2*n; i++)cout<<ans[i]<<" ";
}

