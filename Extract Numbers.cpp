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
string s,a,b;
vector <string> v;
bool check(string x)
{
    if(x.size()==1 && x[0]=='0')return true;
    if(x[0]=='0'|| x[0]<'0' || x[0]>'9')return false;
    for(int i=1; i<x.size(); i++)
    {
        if(x[i]<'0' || x[i]>'9')return false;
    }
    return true;
}
int main()
{
    fast_IO();
    cin>>s;
    int start=0;
    for(int i=0; i<=s.size(); i++)
    {
        if(s[i]==',' || s[i]==';' || i==s.size())
        {
            string tmp=s.substr(start,i-start);
            start=i+1;
            v.push_back(tmp);
        }
    }
    bool ka=false,kb=false;
    for(auto i : v)
    {
        if(check(i))
        {
            if(!ka)ka=true,a=a+i;
            else a.push_back(','),a=a+i;
        }
        else
        {
            if(!kb)kb=true,b=b+i;
            else b.push_back(','),b=b+i;
        }
    }
    a='"'+a+'"';
    b='"'+b+'"';
    if(!kb)b='-';
    if(!ka)a='-';
    cout<<a<<'\n'<<b;
}

