// Rajesh :: QHTW
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int  mod = 1e9+7;
void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    ordered_set o;
    int mw=mod;
    for(int i=0;i<n;i++){
        if(o.order_of_key(a[i])>0 && mw>a[i]){
            ans++;
            mw=a[i];
        }
        o.insert(a[i]);
    }
    cout<<ans<<endl;
    return;
}
signed main(){  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    /*     // if not used u might face memory limit exceed!
    #ifndef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    */
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
        // break;
    }
    return 0;
}
        // function<void (int ,int)> dfs1=[&](int st,int p){
        // };

// for B check for the constraints properly // what to use!!
// cout<<fixed<<setprecision(9)<<a<<endl;