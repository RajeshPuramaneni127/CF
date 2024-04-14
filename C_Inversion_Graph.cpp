// Rajesh :: DGTW
#include <bits/stdc++.h>
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
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
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
int find(vector<int> &par,vector<int>& sz,int v){
    if(par[v]==v) return v;
    return par[v] = find(par,sz,par[v]);
}
void unite(vector<int> &par,vector<int>& sz,int a,int b){
    a = find(par,sz,a);
    b = find(par,sz,b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        par[b] = a;
        sz[a] +=sz[b];
    }
    return;
}
void solve(){
    int n;cin>>n;
    vi p(n+1);
    vi par(n+1),sz(n+1);
    for(int i=1;i<=n;i++){
        par[i] = i;sz[i] = 1;
    }
    stack<int> maxi;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        if(maxi.empty() || p[maxi.top()]<p[i]){
            maxi.push(i);
        }else{
            int currmaxi = maxi.top();
            while(!maxi.empty() && p[maxi.top()]>p[i]){
                unite(par,sz,maxi.top(),i);
                maxi.pop();
            }
            maxi.push(currmaxi);
        }
    }
    set<int> st;
    for(int i=1;i<=n;i++){
        st.insert(find(par,sz,i));
    }
    cout<<st.size()<<endl;
    return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
    // freopen("input.txt", "r" , stdin);
    // freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}