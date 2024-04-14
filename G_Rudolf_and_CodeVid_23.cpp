// Rajesh :: JGTW
#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define endl "\n"
#define int long long
#define PNO cout<<"NO"<<endl
#define PYES cout<<"YES"<<endl
#define PYes cout<<"Yes"<<endl
#define PNo cout<<"No"<<endl
#define pb emplace_back
#define ppb pop_back
#define mk make_pair
#define F first
#define S second
#define M_PI 3.14159265358979323846
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i = b-1;i>=a;i--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pair<int,int>>

#define inf 1e9
#define INF 1e18
#define mod 1000000007
#define modd 998244353
// #define N 2000006
const double PI = 3.1415926535897932384626433832795;

int fact(int n){if(n==0)return 1;int ans =1;while(n--){ans = (ans*(n+1))%mod;}return ans;}
int ncr(int n,int r){int res = 1;if(r>n-r) r = n-r;for(int i=0;i<r;i++){res *= (n-i);res *= pow(i+1,-1);}return res;}
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int digitsum(int a){ int ans =0;while(a>0){ans+=a%10;a/=10;}return ans;}
double bpow(double x, int y){double res = 1; while (y > 0){if (y & 1) res *= x; y = y >> 1LL, x *= x;} return res;}
int powm(int x,int y,int M){if(x==0 && y==0) return (int)1;if(x==0) return (int)0;if(y==0) return (int)1;if(y==1) return x%M;int k = powm(x,y/2,M);if(y%2) return (((x*k)%M)*k)%M;else return (k*k)%M;}

void SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return;
}

bool comp(const pair<int,int> & p1,const pair<int,int>& p2){
    if(p1.first==p2.first) return p1.second<p2.second;
    return p1.first<p2.first;
}

void solve(){
    int n,m;cin>>n>>m;
    bitset<10> tmp;
    cin>>tmp;
    int s = (int)tmp.to_ulong();
    vector<pair<pair<int,int>,int>> edg(m);
    for(int i=0;i<m;i++){
        cin>>edg[i].second;
        cin>>tmp;
        edg[i].first.first = ((1<<n)-1)^(int)tmp.to_ulong();
        cin>>tmp;
        edg[i].first.second = (int)tmp.to_ulong();
    }
    vector<int> dist((1<<n),INT_MAX);
    dist[s] = 0;
    set<pair<int,int>> st;
    st.insert({0,s});
    while(!st.empty()){
        auto [d,v] = *st.begin();
        st.erase(st.begin());
        for(int i=0;i<m;i++){
            int nxt = v&edg[i].first.first;
            nxt|= edg[i].first.second;
            if(dist[nxt]>d+edg[i].second){
                st.erase({dist[nxt],nxt});
                dist[nxt] = d+edg[i].second;
                st.insert({dist[nxt],nxt});
            }
        }
    }
    if(dist[0]==INT_MAX){
        cout<<"-1"<<endl;return;
    }
    cout<<dist[0]<<endl;
    return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
    /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    */
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}