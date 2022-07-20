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
int a[27];
vector <int> store;
int main()
{
    fast_IO();
    cin>>s;
    for(int i=0; i<s.size(); i++)a[int(s[i]-'a')]++;
    for(int i=0; i<26; i++)
    {
        if(a[i]%2!=0)store.push_back(i);
    }
    for(int i=0; i<store.size()/float(2); i++)a[store[i]]++,a[store[store.size()-i-1]]--;
    char tmp;
    string luu;
    for(int i=0; i<26; i++)
    {
        if(a[i]%2!=0)tmp=char(i+'a');
        for(int j=1; j<=a[i]/2; j++)luu.push_back(char(i+'a'));
    }
    cout<<luu;
    if(s.size()%2!=0)cout<<tmp;
    reverse(luu.begin(),luu.end());
    cout<<luu;
}

