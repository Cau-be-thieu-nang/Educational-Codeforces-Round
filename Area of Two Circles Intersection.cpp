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
int main()
{
    fast_IO();
    long double X,Y,R,x,y,r,a,b,c,n,m,ans=0;
	cin>>X>>Y>>R>>x>>y>>r;
	n=(X-x)*(X-x)+(Y-y)*(Y-y);
	n=sqrt(n);
	long double p=acos(-1);
	if(n>=R+r) ans=0;
	else if(n+r<=R||n+R<=r) ans=p*min(r,R)*min(r,R);
	else {
		a=acos((R*R+n*n-r*r)/(2*R*n));
		b=acos((r*r+n*n-R*R)/(2*r*n));
		ans=(long double)(R*R*a+r*r*b-R*R*sin(a)*cos(a)-r*r*sin(b)*cos(b));
	}
	cout<<fixed<<setprecision(20)<<ans;
}

