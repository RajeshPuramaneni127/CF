

/**
 *       Code By Rajesh
 *       Date : Y/B/TW 
 **/
 
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
    if((i1.first + i1.second) == (i2.first + i2.second)) return i1.first<i2.first;
    return (i1.first + i1.second) < (i2.first + i2.second);
}

void solve(){
    int n;cin>>n;string s;cin>>s;int x,y;
    if(n%2==0){
        x = n/2-1,y=n/2;
    }else{
        x = n/2;y=n/2;
    }
    bool flag = false,flag2 = false;
    for(;x>=0&&y<n;x--,y++){
        if(flag &&flag2){
            if(s[x]!=s[y]){
                PNO;return;
            }continue;
        }
        if(flag){
            if(s[x]==s[y]){
                flag2=true;
            }else{
                if(s[y]=='0'){
                s[y] = '1';
                }else{
                s[y] = '0';
            }
            }
        }
        else if(s[x]!=s[y]){
            flag = true;
            if(s[y]=='0'){
                s[y] = '1';
            }else{
                s[y] = '0';
            }
        }
        if(s[x]!=s[y]){
            PNO;return;
        }
    }
    PYES;
    return;
}

 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t;cin>>t;
    while(t--)
	 solve();
    return 0;
}