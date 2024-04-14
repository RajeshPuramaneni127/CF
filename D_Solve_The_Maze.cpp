// Rajesh :: WFTW
#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cassert>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <bitset>
#include <chrono>
#include <random>
#include <fstream>
#include <iterator>
#include <complex>
//#include "DSU.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> orderedMultiset;
#define bug(args ...) cerr << __LINE__ << ">> ", err(new istringstream(string(#args)), args), cerr << '\n'
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
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pair<int,int>>
 
#define inf 1e9
#define INF 1e18
#define mod 1000000007
#define modd 998244353
// #define N 2000006
const double PI = 3.1415926535897932384626433832795;
 
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef unsigned long long ull; typedef long long ll; typedef long double ld; typedef pair<int, int> pii; typedef pair<double, double> pdd; typedef pair<long long, long long> pll; typedef cc_hash_table<int, int, hash<int>> intHashTable; typedef tuple<int, int, int> tiii;
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
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
    return;
}
 
bool comp(const pair<int,int> & p1,const pair<int,int>& p2){
    if(p1.first==p2.first) return p1.second<p2.second;
    return p1.first<p2.first;
}
int n,m;
bool check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m){
        return true;
    }return false;
}
vector<int> dx = {-1,0,1,0}, dy = {0,-1,0,1};

int find(int par[],int v){
    if(v==par[v]) return v;
    return par[v] = find(par,par[v]);
}

bool unite(int par[],int sz[],int a,int b){
    a = find(par,a);
    b = find(par,b);
    if(a==b) return true;
    if(sz[a]<sz[b]) swap(a,b);
    sz[a]+=sz[b];
    par[b] = a;
    return false;
}
                                          // solve this problem using dfs and bfs ;
void solve(){                            // solve this contest // as well as 
    cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='B'){
                for(int k=0;k<4;k++){
                    int newx = i+dx[k];
                    int newy = j+dy[k];
                    if(check(newx,newy)){
                        if(v[newx][newy]=='G'){
                            PNo;return;
                        }else if(v[newx][newy]=='.'){
                            v[newx][newy] = '#';
                        }
                    }
                }
            }
        }
    }
    if(v[n-1][m-1]=='B'){
        PNo;return;
    }
    int par[n*m],sz[n*m];
    for(int i=0;i<n*m;i++){
        par[i] = i;sz[i] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]!='#' &&check(i,j+1)){
                if(v[i][j+1]!='#'){
                    unite(par,sz,i*m+j,i*m+j+1);
                }
            }
            if(v[i][j]!='#' && check(i+1,j)){
                if(v[i+1][j]!='#'){
                    unite(par,sz,(i+1)*m+j,i*m+j);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='G'){
                if(!unite(par,sz,i*m+j,n*m-1)){
                    PNo;return;
                }
            }
        }
    }
    PYes;
    return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
