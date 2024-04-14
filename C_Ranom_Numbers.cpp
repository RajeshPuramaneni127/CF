// Rajesh :: MFTW
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

int getScore(string& s){
    bool a=false,b=false,d=false,c=false,e=false;
    int score=0;
    int n=s.size();
    for(int i=n-1;i>=0;i--){
        if(s[i]=='A'){
            a=true;
            if(b || c || d || e) score-=1;
            else score+=1;
        }
        if(s[i]=='B'){
            b=true;
            if(c || e ||  d)  score-=10;
            else score+=10;
        }
        if(s[i]=='C'){
            c=true;
            if(d || e)   score-=100;
            else score+=100;
        }
        if(s[i]=='D'){
            d=true;
            if(e) score-=1000;
            else score+=1000;
        }
        if(s[i]=='E'){
            e=true;
            score+=10000;
        }
        // cout<<score<<" ";
        
    }
    return score;
}
void solve(){
    int n=1,m=0;
    string s;
    cin>>s;
    n=s.size();
    int loca=-1,locb=-1,locc=-1,locd=-1,loce=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='A' && loca==-1)   loca=i;
        if(s[i]=='B' && locb==-1)   locb=i;
        if(s[i]=='C' && locc==-1)   locc=i;
        if(s[i]=='D' && locd==-1)   locd=i;
        if(s[i]=='E' && loce==-1)   loce=i;
        
    }
    int res=getScore(s);
    if(loca!=-1){
        s[loca]='B';
        res=max(res,getScore(s));
        s[loca]='C';
        res=max(res,getScore(s));
        s[loca]='D';
        res=max(res,getScore(s));
        s[loca]='E';
        res=max(res,getScore(s));
        s[loca]='A';
    }
    if(locb!=-1){
        s[locb]='C';
        res=max(res,getScore(s));
        s[locb]='D';
 
        res=max(res,getScore(s));
        s[locb]='E';
        res=max(res,getScore(s));
        s[locb]='B';
    }
    if(locc!=-1){
        s[locc]='D';
        res=max(res,getScore(s));
 
        s[locc]='E';
        res=max(res,getScore(s));
        s[locc]='C';
    }
    if(locd!=-1){
        s[locd]='E';
        res=max(res,getScore(s));
        s[locd]='D';
    }
    loca=-1,locb=-1,locc=-1,locd=-1,loce=-1;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='A' && loca==-1)   loca=i;
        if(s[i]=='B' && locb==-1)   locb=i;
        if(s[i]=='C' && locc==-1)   locc=i;
        if(s[i]=='D' && locd==-1)   locd=i;
        if(s[i]=='E' && loce==-1)   loce=i;
    }
    if(loce!=-1){
        s[loce]='B';
        res=max(res,getScore(s));
        s[loce]='C';
        res=max(res,getScore(s));
        s[loce]='A';
        res=max(res,getScore(s));
        s[loce]='D';
        res=max(res,getScore(s));
        s[loce]='E';
        
    }
    if(locd!=-1){
        s[locd]='B';
        res=max(res,getScore(s));
        s[locd]='C';
        res=max(res,getScore(s));
        s[locd]='A';
        res=max(res,getScore(s));
        s[locd]='D';
    }
    if(locc!=-1){
        s[locc]='A';
        res=max(res,getScore(s));
        s[locc]='B';
        res=max(res,getScore(s));
        s[locc]='C';
    }
    if(locb!=-1){
        s[locb]='A';
        res=max(res,getScore(s));
        s[locb]='B';
    }
    // cout<<s<<"\n";
    cout<<res<<"\n";
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