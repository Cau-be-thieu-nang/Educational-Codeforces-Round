#include <bits/stdc++.h>
#define iat 3001
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
int n,m;
ll ans;
string s;
bitset <iat> a[iat],b[iat],c[iat];
int main()
{
    fast_IO();
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        for(int j=0; j<m; j++)a[i][j]=(s[m-1-j]=='z');
    }
    for(int i=0; i<n; i++)b[i].set(),c[i].set();
    for(int j=0; j<n && j<m; j++)
    {
        for(int i=0; i<n; i++)b[i]&=a[i]>>j;
        for(int i=0; i+j<n; i++)
        {
            c[i]&=a[i+j]>>j,
            ans+=(b[i]&b[i+j]&c[i]).count();
        }
    }
    cout<<ans;
}


/// CODE TLE :)


//#include <bits/stdc++.h>
//#define iat 9000001
//#define ll long long
//#define LOG 20
//#define MASK(i) (1LL << (i)) // 2 luy thua i
//#define BIT(x,i) (((x) >> (i)) & 1) // lay ra bit thu i cua so x
//using namespace std;
//void fast_IO()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    if(fopen("t.inp","r"))
//    {
//        freopen("t.inp","r",stdin);
//        freopen("t.out","w",stdout);
//    }
//}
//int n,m,dem,b[3001][3001],c[iat],d[3001][3001],sum[iat];
//ll ans;
//char a[3001][3001];
//int main()
//{
//    fast_IO();
//    cin>>n>>m;
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=m; j++)cin>>a[i][j],ans+=(a[i][j]=='z');
//    }
//    for(int j=1; j<=m; j++)
//    {
//        int i=1,_i=i,_j=j;
//        while(_i<=n && _j>=1)b[_i][_j]=++dem,c[dem]=(a[_i][_j]=='z' ? 1 : 0),_i++,_j--;
//    }
//    for(int i=2; i<=n; i++)
//    {
//        int j=m,_i=i,_j=j;
//        while(_i<=n && _j>=1)b[_i][_j]=++dem,c[dem]=(a[_i][_j]=='z' ? 1 : 0),_i++,_j--;
//    }
//    for(int i=1; i<=dem; i++)sum[i]=sum[i-1]+c[i];
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=m; j++)d[i][j]=d[i][j-1]+(a[i][j]=='z');
//    }
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=m; j++)
//        {
//            int _i=i,_j=j;
//            for(; ;)
//            {
//                _i++,_j++;
//                if(_i>n || _j>m)break;
//                if((d[i][_j]-d[i][j-1]==_j-j+1) && (d[_i][_j]-d[_i][j-1]==_j-j+1) && (sum[b[_i][j]]-sum[b[i][_j]-1]==b[_i][j]-b[i][_j]+1))
//                {
//                    ans++;
//                }
//            }
//        }
//    }
//    cout<<ans;
//}
//
