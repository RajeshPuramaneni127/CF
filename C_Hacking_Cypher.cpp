// Rajesh :: BFTW
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
#define N 2000006
const double PI = 3.1415926535897932384626433832795;
 
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef unsigned long long ull; typedef long long ll; typedef long double ld; typedef pair<int, int> pii; typedef pair<double, double> pdd; typedef pair<long long, long long> pll; typedef cc_hash_table<int, int, hash<int>> intHashTable; typedef tuple<int, int, int> tiii;
int fact(int n){if(n==0)return 1;int ans =1;while(n--){ans *=(n+1);}return ans;}
int ncr(int n,int r){int res = 1;if(r>n-r) r = n-r;for(int i=0;i<r;i++){res *= (n-i);res *= pow(i+1,-1);}return res;}
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int digitsum(int a){ int ans =0;while(a>0){ans+=a%10;a/=10;}return ans;}
double bpow(double x, int y){double res = 1; while (y > 0){if (y & 1) res *= x; y = y >> 1LL, x *= x;} return res;}
// template <class T> T kruskal(int n, vector<pair<T, pair<T,T>>> ed) {
// 	sort(all(ed));
// 	T ans = 0;
// 	DSU D;
// 	D.init(n);  // edges that unite are in MST
// 	trav(a, ed) if (D.unite(a.s.f, a.s.s)) ans += a.f;
// 	return ans;
// }
 
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
bool comp(vector<ll>&a,vector<ll>&b){
    if(a[1]==b[1]) return a[0]<b[0];
    return a[1]<b[1];
}
 
bool comp2(pair<ll,ll> i1, pair<ll,ll> i2)
{
    if(i1.first==i2.first){
        return i1.second<i2.second;
    }else{
        return i1.first>i2.first;
    }
}
 
struct ComparePairs {
    bool operator()(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2) {
        return p1.first < p2.first;
    }
};
 

void solve(){
    string s;
	cin>>s;
	int a,b;
	cin>>a>>b;
    int n = s.size();
    int rema[n],remb[n];
	rema[0] = (s[0]-'0')%a;
	remb[n-1] = (s[n-1]-'0')%b;
	int p=10;
	rep(l,1,n-1){
		rema[l] = (rema[l-1]*10 + (s[l]-'0'))%a;
		int r=n-l-1;
		remb[r] = ((s[r]-'0')*p + remb[r+1])%b;
		p = (p*10)%b;
	}
	//rep(i,1,n-1) cout<<rema[i]<<' ';cout<<nl;
	//rep(i,1,n) cout<<remb[i]<<' ';cout<<nl;
	int pos=-1;
	rep(i,0,n-1){
		if (rema[i]==0 && remb[i+1]==0 && s[i+1]!='0'){
			cout<<"YES\n"; pos=i;break;
		}
	}
	if (pos==-1) cout<<"NO";
	else{
		rep(i,0,pos+1) cout<<s[i];
		cout<<endl;
		rep(i,pos+1,n) cout<<s[i];
	}
    return; 
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
    // int t;cin>>t;
    // for(int i=1;i<=t;i++){
    //     //cout<<"Case #"<<i<<": ";
        solve();
    // }
    return 0;
}