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
int h1,h2,a,b;
signed main()
{
    fast_IO();
    cin>>h1>>h2>>a>>b;
    if(h1+8*a>=h2)cout<<0;
	else if(a>b)
    {
		int num=h2-h1-8*a,den=12*(a-b);
		cout<<(num+den-1)/den;
	}
	else cout<<-1;
}

