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
int n,p,q;
string s;
void solve()
{
    for(int i=0; i<=n/p; i++)
    {
        for(int j=0; j<=(n-i*p)/q; j++)
        {
            if((i*p+j*q)==n)
            {
                cout<<i+j<<'\n';
                int pos=0;
                for(int x=1; x<=i; x++)
                {
                    for(int y=1; y<=p; y++)
                    {
                        cout<<s[pos];
                        pos++;
                    }
                    cout<<'\n';
                }
                for(int x=1; x<=j; x++)
                {
                    for(int y=1; y<=q; y++)
                    {
                        cout<<s[pos];
                        pos++;
                    }
                    cout<<'\n';
                }
                return;
            }
        }
    }
    cout<<-1;
}
int main()
{
    fast_IO();
    cin>>n>>p>>q>>s;
    solve();
}

