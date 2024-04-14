#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;cin>>n;
    priority_queue<int> pq;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;pq.push(x);
    }
    int p,q;cin>>p>>q;
    int neg=0;
    int ans=0;
    while(pq.size() && pq.top()>neg){
        int count = (pq.top()-neg+p-1)/p;
        neg+=count*q;
        ans+=count;pq.pop();
    }
    cout<<ans<<endl;
    return;
}

signed main(){
    solve();
    return 0;
}