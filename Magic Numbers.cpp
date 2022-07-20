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
const int mod=1e9+7;
ll dp[2001][2001][2];
int d,m;
ll solve(string& num, int n, int curnum, bool tight)
{
    if(n==num.size())return !curnum;
    ll ans=0;
    if(dp[n][curnum][tight]!=-1)return dp[n][curnum][tight];
    int ub=(tight ? (num[n]-'0') : 9);
    for(int dig=0; dig<=ub; dig++)
    {
        if(n%2==0 && dig==d)continue;
        if(n%2!=0 && dig!=d)continue;
        ans=(ans+solve(num,n+1,(curnum*10+dig)%m,tight&(dig==ub)))%mod;
    }
    return dp[n][curnum][tight]=ans;
}
bool check(string& num)
{
    int curnum=0;
    for(int i=0; i<num.size(); i++)
    {
        if(i%2!=0 && int(num[i]-'0')!=d)return false;
        if(i%2==0 && int(num[i]-'0')==d)return false;
        curnum=(curnum*10+int(num[i]-'0'))%m;
    }
    if(curnum)return false;
    return true;
}
int main()
{
    fast_IO();
    string a,b;
    cin>>m>>d>>a>>b;
    memset(dp,-1,sizeof(dp));
    ll ansb=solve(b,0,0,1);
    memset(dp,-1,sizeof(dp));
    ll ansa=solve(a,0,0,1);
    cout<<(ansb-ansa+check(a)+mod)%mod;
}
