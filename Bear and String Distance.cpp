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
int n,k;
string s,ans;
int main()
{
    fast_IO();
    cin>>n>>k>>s;
    for(int i=0; i<n; i++)
    {
        int a=s[i]-'a',z='z'-s[i];
        if(a>z)
        {
            if(k>=a)ans.push_back('a'),k-=a;
            else ans.push_back(char(s[i]-k)),k=0;
        }
        else
        {
            if(k>=z)ans.push_back('z'),k-=z;
            else ans.push_back(char(s[i]+k)),k=0;
        }
    }
    if(k==0)cout<<ans;
    else cout<<-1;
}

