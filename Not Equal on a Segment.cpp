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
int n,m,a[iat],b[iat];
int main()
{
    fast_IO();
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i-1]==a[i])b[i]=b[i-1];
        else b[i]=i-1;
    }
    while(m--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        if(a[r]!=x)cout<<r<<'\n';
        else
        {
            if(b[r]<l)cout<<-1<<'\n';
            else cout<<b[r]<<'\n';
        }
    }
}

