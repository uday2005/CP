#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll mod_pow ( ll base , ll exp , int mod){
    ll result = 1;
    base %= mod;

    while(exp > 0){
        if (exp % 2 == 1) { // If the current bit is set
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main(){
    ll n ;
    cin >> n;
    
    // ll result = 1;
    // while(n > 0){
    //     result = (1LL* 2) * result;
    //     n--;
    // }
    
    // cout << (1LL << n);
    cout << mod_pow(2, n, MOD) << endl;
}

#include <iostream>

using namespace std;

int M = 1e9+7;
int n;

int main() {
    cin >> n;
    int t = 1;
    for (int i = 1; i <= n; i++) t = (t*2)%M;
    cout << t << "\n";
}