#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n=1,m=0;
    string s;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int l=0,r=0;
    set<int> vals;
    for(int i=0;i<n;i++){
        if(v[i]==-1)    l++;
        else if(v[i]==-2)   r++;
        else vals.insert(v[i]);
    }
    int res=min(m,max(l+(int)vals.size(),r+(int)vals.size()));
    int sz=vals.size();
    int left=0;
    for(auto& i:vals){
        res=max(res,1+min(i-1,l+left)+min(m-i,r+sz-left-1));
        left++;
    }
 
    cout<<res<<"\n";
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