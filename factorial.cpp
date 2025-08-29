#include<iostream>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
ll N = 1e5+1;

ll power(ll a, ll b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res%mod;
}

ll factorial[300006];
ll invfact[300006];

void fact() {   
    int n = 300005;
    factorial[0] = 1;
    for(int i = 1; i <= n; i++){
        factorial[i] = (factorial[i - 1] * i) % mod;
    }

    invfact[n] = power(factorial[n], mod - 2);
    for(int i = n - 1; i >= 0; i--){
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
    }
}

ll nCr(int n, int r){
    ll factorial[300006]; 
    ll invfact[300006];
    if(n < r || r < 0) return 0;
    return (((factorial[n] * invfact[r]) % mod) * invfact[n - r]) % mod;
}

int main(){
     int ans = nCr(6, 2);
     cout<<ans<<endl;
     return 0;
}