#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    for(int i=0;i<n-1;i++){
        if(a[i]>i+1 && a[i+1]<=i+1){
            cout<<i+1<<endl;return;
        }
    }
    if(a[0]==0){
        cout<<0<<endl;
    }else{
        cout<<-1<<endl;
    }
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