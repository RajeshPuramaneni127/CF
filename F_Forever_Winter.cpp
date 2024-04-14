#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[300];
void solve() {
  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    adj[i].clear();
  }
  for(int i=1; i<=m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int cnt =0 ;
  for(int i=1; i<=n; i++) cnt += (adj[i].size() == 1);
  int x = m - cnt;
  int y = m / x - 1;
  cout << x << " " << y << "\n";
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