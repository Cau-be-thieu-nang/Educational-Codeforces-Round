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
int n,a[iat];
map <int,int> c;
vector <pair<int,int>> ans;
int main()
{
    fast_IO();
    cin>>n;
    int dau=1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        c[a[i]]++;
        if(c[a[i]]==2)c.clear(),ans.push_back({dau,i}),dau=i+1;
    }
    if(ans.size()==0)cout<<-1;
    else
    {
        cout<<ans.size()<<'\n';
        for(int i=0; i<ans.size()-1; i++)cout<<ans[i].first<<" "<<ans[i].second<<'\n';
        cout<<ans[ans.size()-1].first<<" "<<n;
    }
}

