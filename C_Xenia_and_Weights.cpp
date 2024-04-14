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

string s;
int m,c=0;
vector<int>vf;
bool btrack(int j, int s1, int s2, vector<int>& v)
{
    if(c==1)
        return true;
    if (j == m)
    {
        // cout<<"* ";
        c=1;
        vf=v;
        return true;
    }
    for (int i = 0; i < 10; i++)
    {
        if(s[i]=='1')
        {
            if(!v.empty())
                if(v.back()==i+1)
                    continue;
            if(j%2==0&&s2+i+1>s1)
            {
                v.push_back(i+1);
                btrack(j+1,s1,s2+i+1,v);
                v.pop_back();
            }
            else if(j%2==1&&s1+i+1>s2)
            {
                v.push_back(i+1);
                btrack(j+1,s1+i+1,s2,v);
                v.pop_back();
            }
 
        }
    }
    if(c==1)
        return true;
    return false;
}
void solve(){                            
   cin >> s;
    cin >> m;
    vector<int>vif;
 
    btrack(0,0,0,vif);
    if(c==1)
    {
        cout<<"YES"<<endl;
        for(auto v:vf)
            cout<<v<<" ";
 
    }
    else
    {
        cout<<"NO";
    }
    return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
    solve();
    return 0;
}
