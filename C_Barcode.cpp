// Date : 22/05/2023
// Submited By Rajesh
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
#pragma GCC optimize("unroint-loops")
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
#define aint(v) v.begin(),v.end()
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
typedef unsigned long long uint; typedef long long ll; typedef long double ld; typedef pair<int, int> pii; typedef pair<double, double> pdd; typedef pair<long long, long long> pint; typedef cc_hash_table<int, int, hash<int>> intHashTable; typedef tuple<int, int, int> tiii;
int fact(int n){if(n==0)return 1;int ans =1;while(n--){ans *=(n+1);}return ans;}
int ncr(int n,int r){int res = 1;if(r>n-r) r = n-r;for(int i=0;i<r;i++){res *= (n-i);res *= pow(i+1,-1);}return res;}
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int digitsum(int a){ int ans =0;while(a>0){ans+=a%10;a/=10;}return ans;}
double bpow(double x, int y){double res = 1; while (y > 0){if (y & 1) res *= x; y = y >> 1ll, x *= x;} return res;}
 
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
bool comp(vector<int>&a,vector<int>&b){
    if(a[1]==b[1]) return a[0]<b[0];
    return a[1]<b[1];
}
 
bool comp2(pair<int,int> i1, pair<int,int> i2)
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
 

vector<int> bfs(vector<vector<int>>&edge, int start, int n)
{
      int curr = start;
      vector<bool> visited(n+1,0);
      vector<int> lvl(n+1);
      lvl[curr]=0;
      queue<int> qq;
      qq.push(curr);
      visited[curr]=1;
 
 
        while(!qq.empty()) 
        {
               curr=qq.front(); 
               for( int x : edge[curr] ) 
            {
                  if(!visited[x]) 
                  {
                        lvl[x] = 1 + lvl[curr];
                        qq.push(x);
                        visited[x] = 1;
                  }
            }
            qq.pop();
      }
      return lvl;
}
 
 
void dfs(vector<vector<int>>&edge, int curr, int prev)
{
       for(int x:edge[curr])
       {
            if(x!=prev)
            {
                  dfs(edge,x,curr);
            }
       }
}
 
 
vector <string> bor = {"YES","NO"};
 
bool isval(vector<int>&arr,int n,int mid)
{
      int temp=0;
      for(int i=1;i<n;i++)
      {
            temp+=(mid-arr[i]);
      }
      if(temp>=arr[0]) return 1;
      return 0;
}
void solve()
{
      int n;
      cin>>n;
      vector<int>arr(n); 
      for(int i=0;i<n;i++){
        cin>>arr[i];
      }
      sort(arr.begin(),arr.end());
      int low=0,high=(int)(1e12)+10;
      low=arr[n-1];
      int ans=high;
      while(low<=high)
      {
            int mid=low+(high-low)/2;
            if(isval(arr,n,mid))
            {
                  high=mid-1;
                  ans=mid;
 
            }
            else
            {
                  low=mid+1;
            }
 
      }
cout<<ans<<"\n";       
       
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