// Rajesh :: AHTW
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
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
// #define INF 1e18
#define mod 1000000007
#define modd 998244353
// #define N 2000006
const double PI = 3.1415926535897932384626433832795;
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_pset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
int fact(int n){if(n==0)return 1;int ans =1;while(n--){ans = (ans*(n+1))%mod;}return ans;}
int ncr(int n,int r){int res = 1;if(r>n-r) r = n-r;for(int i=0;i<r;i++){res *= (n-i);res *= pow(i+1,-1);}return res;}
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int digitsum(int a){ int ans =0;while(a>0){ans+=a%10;a/=10;}return ans;}
double bpow(double x, int y){double res = 1; while (y > 0){if (y & 1) res *= x; y = y >> 1LL, x *= x;} return res;}
int powm(int x,int y,int M){if(x==0 && y==0) return (int)1;if(x==0) return (int)0;if(y==0) return (int)1;if(y==1) return x%M;int k = powm(x,y/2,M);if(y%2) return (((x*k)%M)*k)%M;else return (k*k)%M;}

void SieveOfEratosthenes(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    return;
}
    
bool comp(const pair<int,int> & p1,const pair<int,int>& p2){
    if(p1.first==p2.first) return p1.second<p2.second;
    return p1.first<p2.first;
}
const int maxn = 1e5+1;
vector<int> adj[maxn];
int par[maxn];
int find(int v){
    if(v==par[v]) return v;
    return par[v] = find(par[v]);
}

void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        par[i] =i;
    }
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vi val(n);
    for(int i=0;i<n;i++) cin>>val[i];
    vector<vector<int>> node(n,vector<int> (2));
    vector<vector<int>> subtree(n,vector<int> (2));
    for(int i=0;i<n;i++){
        node[i][0] = val[i];
        node[i][1] = i;
        subtree[i][0] = val[i];        // val of the maximum node in the subtree!!
        subtree[i][1] = 1;            // count of no. of nodes in the with maxvalue in the subtree!!
    }
    sort(node.begin(),node.end());
    int ans=0;
    for(auto v:node){
        int p = find(v[1]);
        for(auto u:adj[v[1]]){
            int nxt = find(u);
            if(val[nxt]>v[0] || p==nxt) continue;
            if(subtree[nxt][0]==subtree[p][0]){
                ans+=subtree[nxt][1]*subtree[p][1];
                subtree[p][1]+=subtree[nxt][1];
            }
            // subtree[nxt] = subtree[p];
            par[nxt] = p;
        }
    }
    cout<<ans<<endl;
    return;
}
signed main(){  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    /*     // if not used u might face memory limit exceed!
    #ifndef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    */
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
        // function<void (int ,int)> dfs1=[&](int st,int p){
        // };

// for B check for the constraints properly // what to use!!

