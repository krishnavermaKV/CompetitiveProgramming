#include<bits/stdc++.h>
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

long long power_inverse(long long a) {
    return power(a, mod - 2);
} 

const int MAX_X = 30;  

vector<int> powerOfTwo(MAX_X+1);
void precompute() {
    powerOfTwo[0] = 1;
    for (int i = 1; i <= MAX_X; ++i) {
        powerOfTwo[i] = powerOfTwo[i - 1] * 2;
    }
}

int main(){
    int pow = power(4, 5);
    cout<<pow<<endl;
     return 0;
}