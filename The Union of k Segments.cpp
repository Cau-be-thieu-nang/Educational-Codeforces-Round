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
int n,k,cnt;
vector <pair<int,int>> v,ans;
int main()
{
    fast_IO();
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        v.push_back({l,0});
        v.push_back({r,1});
    }
    sort(v.begin(),v.end());
    int l;
    for(auto i : v)
    {
        if(i.second)
        {
            if(cnt==k)ans.push_back({l,i.first});
            cnt--;
        }
        else
        {
            cnt++;
            if(cnt==k)l=i.first;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto i : ans)cout<<i.first<<" "<<i.second<<'\n';
}

