#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , x ;
    cin  >> n >> x;
    vector <int> arr;
    int count = 0;
    int w;

    for(int i = 0; i< n ; i++){
        cin >> w;
        arr.push_back(w);
    }
    sort(arr.begin(), arr.end());
    
    for(int j = 0; j< n ;j++){
        for(int i = j+1; i< n ; i++){
            if(arr[i] >x){
                break;
            }
            if((arr[j] +arr[i]) <= x ){
                count ++;
            } 
        }
    }
    cout << count << endl;
   
}

// so the problem is that it is counting the value which is alresdy counted.
