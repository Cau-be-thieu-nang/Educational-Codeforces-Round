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
string s;
ll ans;
int main()
{
    fast_IO();
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        int a=int(s[i]-'0');
        if(a%4==0)ans++;
        if(i)
        {
            int b=int(s[i-1]-'0');
            if((b*10+a)%4==0)ans+=i;
        }
    }
    cout<<ans;
}
