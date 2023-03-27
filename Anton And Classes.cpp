#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

template<class T> T gcd(T a,T b)
{
    if(b == 0)return a;
    return gcd(b,a%b);
}
template<class T> T lcm(T a, T b )
{
    return (a*b)/gcd(a,b);
}

struct data
{
    ll a,b;
};
data p[100];
bool cmp(data f,data s)
{
    if(f.a!=s.a)
        return f.a<s.a;
    return f.b<s.b;
}

void PowerSet(ll a[], int set_size)
{
    ll pow_set_size = 1<<set_size;
    for(ll counter = 0; counter < pow_set_size; counter++)
    {
        for(ll j = 0; j < set_size; j++)
        {
            if(counter & (1<<j))
            {

            }
        }
    }
}

#define Mx 1000005
vector<ll>P;
ll prime[Mx];
void seive()
{
    ll i,j;
    for(i=4; i<=Mx; i+=2)prime[i]=1;
    for(i=3; i*i<=Mx; i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*2; j<=Mx; j+=i)
            {
                prime[j]=1;
            }
        }
    }
    P.push_back(2);
    for(i=3; i<=Mx; i+=2)
    {
        if(prime[i]==0)P.push_back(i);
    }
}

pair<ll,ll>p1[200005],p2[200005];
int main()
{
    ll i,j,n,m,a,b,cnt,ans;
    while(scanf("%lld",&n)==1)
    {

        for(i=0; i<n; i++)
        {
            cin>>p1[i].first>>p1[i].second;
        }
        cin>>m;
        for(i=0; i<m; i++)
        {
            cin>>p2[i].first>>p2[i].second;
        }
        sort(p1,p1+n);
        sort(p2,p2+m);
        ll ans1=0,ans2=0,x,y,r,l;
        x=p2[m-1].first;
        y=p2[m-1].second;
        for(i=0;i<n;i++){
            l=p1[i].first;
            r=p1[i].second;
            if(x>=l && x<=r || y>=l && y<=r){
                continue;
            }
            else{

                ans1=max(x-r,ans1);
            }
        }
        x=p1[n-1].first;
        y=p1[n-1].second;

        for(i=0;i<m;i++){
            l=p2[i].first;
            r=p2[i].second;
            if(x>=l && x<=r || y>=l && y<=r){
                continue;
            }
            else{

                ans2=max(x-r,ans2);
            }
        }
        ll ans=max(ans1,ans2);
        cout<<(ans?ans:0)<<endl;
    }
    return 0;
}

