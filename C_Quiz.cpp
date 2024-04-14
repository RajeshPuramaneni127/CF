// Date : 20/05/2023
#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000009;
long long int modpow( int a , int b )
{
    if( b == 0)
     return 1;
    if( b % 2 == 0)
    {
        long long int x = modpow(a,b/2);
        return (x*x)%mod;
    }
    return (a*modpow(a,b-1));
}
int main() 
{
    int n , m , k ;
    cin >> n >> m >> k;
    int r = m;
    int tmp =  ( (n - n % k) /  k * (k-1) );
    r -= tmp;
    r -= n%k;
    if( r < 0 )
      r = 0;
    long long int ans = modpow(2,r)-1;
    ans *= 2*k;
    ans += ( m - r*k );
    ans %= mod;
    cout << ans;
    return 0;
}