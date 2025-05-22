#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int val;
    vector<int> arr;
    int count = 0;

    for(int i = 0; i< n ; i++){
        cin >> val;
        arr.push_back(val);
    }

    for(int i = 0 ; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            count += (arr[i] - arr[i+1]);
            swap(arr[i] , arr[i+1]);
        }

    }
    cout << count << endl;
}