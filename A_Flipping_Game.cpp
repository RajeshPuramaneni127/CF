//Fucking Life
 
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
 
#define inf 1e9
#define INF 1e18
#define mod 1000000007
#define modd 998244353
#define N 2000006
typedef unsigned long long ull; typedef long long ll; typedef long double ld; typedef pair<int, int> pii; typedef pair<double, double> pdd; typedef pair<long long, long long> pll; typedef cc_hash_table<int, int, hash<int>> intHashTable; typedef tuple<int, int, int> tiii;
int fact(int n){if(n==0)return 1;int ans =1;while(n--){ans *=(n+1);}return ans;}
int ncr(int n,int r){int res = 1;if(r>n-r) r = n-r;for(int i=0;i<r;i++){res *= (n-i);res *= pow(i+1,-1);}return res;}
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int digitsum(int a){ int ans =0;while(a>0){ans+=a%10;a/=10;}return ans;}
double bpow(double x, int y){double res = 1; while (y > 0){if (y & 1) res *= x; y = y >> 1LL, x *= x;} return res;}
 
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
 
/*
vector<int> luckynumbers;
void genposvalues(int value, int sevens , int fours){
    if(value>10000000000LL){
        return;
    }
    if(sevens!=0 && sevens==fours){
        luckynumbers.pb(value);
    }
    genposvalues(value*10+4,sevens , fours+1);
    genposvalues(value*10+7,sevens+1,fours);
    return;
}*/
int findPowerSet(vector<vector<int>>& nums,int n)
{
    int res = 0;
    int bits = nums.size();
    unsigned int pow_set_size = pow(2, bits);
    for (int counter = 0; counter < pow_set_size;counter++) {
        set<int> st;
        for (int j = 0; j < bits; j++) {
            if (counter & (1 << j)) {
                for(int i=0;i<nums[j].size();i++){
                    st.insert(nums[j][i]);
                }
            }
        }
        if(st.size()==n){
            res++;
        }
    }
 
    return res;
}
bool comp(vector<ll>&a,vector<ll>&b){
    if(a[0]+a[1]==b[0]+b[1]) return a[0]<b[0];
    else return a[0]+a[1]<b[0]+b[1];
}
 
bool comp2(pair<ll,ll> i1, pair<ll,ll> i2)
{
    if(i1.first==i2.first){
        return i1.second<i2.second;
    }else{
        return i1.first>i2.first;
    }
}
 
void solve(){
    int n;cin>>n;
    int a[n],sum[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0){
            sum[0] = a[0];
        }else{
            sum[i] = sum[i-1]+a[i];
        }
    }int ans =0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            int x = i-2*sum[j+i-1];
            if(j>0){
                x+=2*sum[j-1];
            }
            x+=sum[n-1];
            ans = max(ans,x);
        }
    }
    cout<<ans<<endl;
    return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    solve();
    return 0;
}