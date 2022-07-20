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
string a,b;
int main()
{
    fast_IO();
    cin>>a>>b;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]!='0')
        {
            a=a.substr(i,a.size()-i);
            break;
        }
        if(i==a.size()-1 && a[i]=='0')a="0";
    }
    for(int i=0; i<b.size(); i++)
    {
        if(b[i]!='0')
        {
            b=b.substr(i,b.size()-i);
            break;
        }
        if(i==b.size()-1 && b[i]=='0')b="0";
    }
    if(a.size()>b.size())cout<<'>';
    else if(a.size()<b.size())cout<<'<';
    else if(a>b)cout<<'>';
    else if(a==b)cout<<'=';
    else cout<<'<';
}

