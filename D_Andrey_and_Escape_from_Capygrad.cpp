// Rajesh :: LHTW
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
#define INF 1e18
#define mod 1000000007
#define modd 998244353
// #define N 2000006
const double PI = 3.1415926535897932384626433832795;
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_pset tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
int fact(int n){if(n==0)return 1;int sum =1;while(n--){sum = (sum*(n+1))%mod;}return sum;}
int ncr(int n,int r){int res = 1;if(r>n-r) r = n-r;for(int i=0;i<r;i++){res *= (n-i);res *= pow(i+1,-1);}return res;}
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int digitsum(int a){ int sum =0;while(a>0){sum+=a%10;a/=10;}return sum;}
double bpow(double x, int y){double res = 1; while (y > 0){if (y & 1) res *= x; y = y >> 1LL, x *= x;} return res;}
int powm(int x,int y,int M){if(x==0 && y==0) return (int)1;if(x==0) return (int)0;if(y==0) return (int)1;if(y==1) return x%M;int k = powm(x,y/2,M);if(y%2) return (((x*k)%M)*k)%M;else return (k*k)%M;}
// vi primes;
void SieveOfEratosthenes(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p] == true) {
            for (int i = 2* p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    // for(int i=0;i<=n;i++){
    //     if(is_prime[i]) primes.push_back(i);
    // }
    return;
}
    
bool comp(const pair<int,int> & p1,const pair<int,int>& p2){
    if(p1.second==p2.second) return p1.first<p2.first;
    return p1.second<p2.second;
}
bool comp2(vector<int>& a,vector<int>&b){
    if(a[2]==b[2]){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    return a[2]<b[2];
}
void solve(){
    int n;cin>>n;
    vector<pair<int,int>> v;
    int l,r,a,b;
    for(int i=0;i<n;i++){
        cin>>l>>r>>a>>b;
        v.push_back({l,b});
    }
    sort(all(v));
    set<pair<int,int>> st;
    st.insert({0,0});
    st.insert({INF,INF});
    for(int i=0;i<n;i++){
        if(i==n-1 || v[i].second<v[i+1].first){
            st.insert(v[i]);
        }else{
            v[i+1].first=  v[i].first;
            v[i+1].second = max(v[i].second,v[i+1].second);
        }
    }
    int q;cin>>q;
    int x;
    for(int i=0;i<q;i++){
        cin>>x;
        auto it = --st.upper_bound({x,INF});
        cout<<max(x,it->second)<<" ";
    }cout<<endl;
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
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
        // break;
    }
    return 0;
}
        // function<void (int ,int)> dfs1=[&](int st,int p){
        // };

// for B check for the constraints properly // what to use!!
// cout<<fixed<<setprecision(9)<<a<<endl;