#include <bits/stdc++.h>
using namespace std;

int main(){
    long long  n;
    cin >> n;

    while(n!= 1){
        cout << n << " ";
        if(n%2 ==0){
            n = 1LL * n/2;
        }
        else{
            n = 1LL * 3 * n + 1;
        }
    }
    cout << n;
}