/*
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
set<pair<deque<int>,int>> st;
void solve(){
    int n;cin>>n;
    int k1,k2;
    deque<int> q1,q2,q3;
    cin>>k1;
    for(int i=0;i<k1;i++){
        int x;cin>>x;
        q1.push_back(x);q3.push_back(x);
    }
    cin>>k2;
    for(int i=0;i<k2;i++){
        int x;cin>>x;
        q2.push_back(x);q3.push_back(x);
    }
    int count = 0;
    while(q1.size() && q2.size()){
        if(st.find({q3,q1.size()})!=st.end()){
            cout<<"-1"<<endl;
            return;
        }
        st.insert({q3,q1.size()});
        int x1 = *q1.begin(),x2 = *q2.begin();
        q1.pop_front();
        q2.pop_front();
        q3.clear();
        if(x1>x2){
            q1.push_back(x2);q1.push_back(x1);
        }else{
            q2.push_back(x1);q2.push_back(x2);
        }
        for(int i=0;i<q1.size();i++){
            q3.push_back(q1[i]);
        }
        for(int i=0;i<q2.size();i++){
            q3.push_back(q2[i]);
        }
        count++;
    }
    if(q1.empty()){
        cout<<count<<" 2"<<endl;
    }else if(q2.empty()){
        cout<<count<<" 1"<<endl;
    }
    return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
    // freopen("input.txt", "r" , stdin);
    // freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
*/
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

void solve(){                  // if n==10 // possible expressable solution might be O(n!) :|
    int n;cin>>n;
    int k1,k2;
    deque<int> q1,q2;
    cin>>k1;
    for(int i=0;i<k1;i++){
        int x;cin>>x;
        q1.push_back(x);
    }
    cin>>k2;
    for(int i=0;i<k2;i++){
        int x;cin>>x;
        q2.push_back(x);
    }
    int count = 0,total = fact(n+1);
    while(q1.size() && q2.size()){
        if(count>=total){
            cout<<"-1"<<endl;return;
        }
        int x1 = *q1.begin(),x2 = *q2.begin();
        q1.pop_front();
        q2.pop_front();
        if(x1>x2){
            q1.push_back(x2);q1.push_back(x1);
        }else{
            q2.push_back(x1);q2.push_back(x2);
        }
        count++;
    }
    if(q1.empty()){
        cout<<count<<" 2"<<endl;
    }else if(q2.empty()){
        cout<<count<<" 1"<<endl;
    }
    return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
    // freopen("input.txt", "r" , stdin);
    // freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}