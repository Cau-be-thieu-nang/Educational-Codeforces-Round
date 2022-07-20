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
ll n,ans;
struct mang
{
    int f,pos;
};
mang a[iat];
bool cmp(mang x, mang y)
{
    return x.f<y.f;
}
int main()
{
    fast_IO();
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].f;
        a[i].pos=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=2; i<=n; i++)ans+=abs(a[i-1].pos-a[i].pos);
    cout<<ans;
}

