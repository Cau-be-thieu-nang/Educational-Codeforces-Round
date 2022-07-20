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
int a,b,c[10]={6,2,5,5,4,5,6,3,7,6};
ll ans;
int main()
{
    fast_IO();
    cin>>a>>b;
    for(int i=a; i<=b; i++)
    {
        string s=to_string(i);
        for(int j=0; j<s.size(); j++)ans+=c[int(s[j]-'0')];
    }
    cout<<ans;
}

