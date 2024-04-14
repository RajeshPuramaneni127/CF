// Rajesh :: (Z+A)GTW
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
// #define INF 1e18
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
vi a;
int n;
void init(int x){
    if(x>n) return;
    if(x%10==0){
        a.push_back(x+1);
        init(x+1);
    }
    if(x>0) a.push_back(x*10);
    if(x>0) init(x*10);
    return;
}
void solve(){
    cin>>n;
    a.clear();
    init(0);
    // cout<<a.size()<<endl;
    // for(int i=0;i<a.size();i++){
    //     cout<<a[i]<<" ";
    // }return;
    sort(all(a));
    vi ans;
    vi dp(n+1,INT_MAX);
    dp[0] = 0;
    vi k(n+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<a.size();j++){
            if(i-a[j]>=0){
                if(dp[i]>dp[i-a[j]]+1){
                    k[i] = a[j];
                    dp[i] = dp[i-a[j]]+1;
                }
            }else break;
        }
    }
    cout<<dp[n]<<endl;
    int x = n;
    for(int i=0;i<dp[n];i++){
        cout<<k[x]<<" ";x -=k[x];
    }cout<<endl;
    return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
    /*
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