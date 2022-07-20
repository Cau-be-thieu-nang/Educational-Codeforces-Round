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
stack <char> st;
string s;
int main()
{
    fast_IO();
    cin>>s;
    int ans=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(' || s[i]=='<' || s[i]=='{' || s[i]=='[')st.push(s[i]);
        else
        {
            if(st.empty())
            {
                cout<<"Impossible";
                return 0;
            }
            else
            {
                char top=st.top();
                st.pop();
                if((top=='(' && s[i]==')') || (top=='[' && s[i]==']') || (top=='<' && s[i]=='>') || (top=='{' && s[i]=='}'))continue;
                ans++;
            }
        }
    }
    if(st.empty())cout<<ans;
    else cout<<"Impossible";
}

