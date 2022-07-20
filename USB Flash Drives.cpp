#include <bits/stdc++.h>
#define iat 109
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
int n,m,a[iat];
ll sum;
int main()
{
    fast_IO();
    cin>>n>>m;
    for(int i=1; i<=n; i++)cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    for(int i=1; i<=n; i++)
    {
        if(sum+a[i]>=m)
        {
            cout<<i;
            break;
        }
        else sum+=a[i];
    }
}

