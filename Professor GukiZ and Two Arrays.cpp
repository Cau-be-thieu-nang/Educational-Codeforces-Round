#include <bits/stdc++.h>
#define iat 2001
#define ll long long
#define LOG 20
#define MASK(i) (1LL << (i)) // 2 luy thua i
#define BIT(x,i) (((x) >> (i)) & 1) // lay ra bit thu i cua so x
#define mid (l+r)/2
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
int n,m,a[iat],b[iat];
vector <pair<int,int>> xuat;
map <ll,pair<int,int>> mp;
ll sa,sb,v;
int main()
{
    fast_IO();
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i],sa+=a[i];
    cin>>m;
    for(int i=1; i<=m; i++)cin>>b[i],sb+=b[i];
    v=abs(sa-sb);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            ll tmpv=abs(sa-sb+2*b[j]-2*a[i]);
            if(tmpv<v)
            {
                v=tmpv;
                xuat.clear();
                xuat.push_back({i,j});
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)mp[2LL*(a[i]+a[j])]={i,j};
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=i+1; j<=m; j++)
        {
            ll tmpv=sa-sb+2LL*(b[i]+b[j]);
            auto it=mp.lower_bound(tmpv);
            if(it!=mp.begin())it--;
            for(int k=1; k<=2; k++)
            {
                if(it==mp.end())break;
                ll tmp=abs(tmpv-it->first);
                auto x=it->second;
                if(tmp<v)
                {
                    v=tmp;
                    xuat.clear();
                    xuat.push_back({x.first,i});
                    xuat.push_back({x.second,j});
                }
                it++;
            }
        }
    }
    cout<<v<<'\n'<<xuat.size()<<'\n';
    for(auto i : xuat)cout<<i.first<<" "<<i.second<<'\n';
}
