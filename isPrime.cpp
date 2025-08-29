#include<bits/stdc++.h>
using namespace std;


vector<bool> sieveOfEratosthenes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes

    for (int num = 2; num * num <= limit; ++num) {
        if (isPrime[num]) {
            for (int multiple = num * num; multiple <= limit; multiple += num) {
                isPrime[multiple] = false;
            }
        }
    }

    return isPrime;
}

int main(){
     
     return 0;
}