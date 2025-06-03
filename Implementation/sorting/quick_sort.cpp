#include <bits/stdc++.h>
using namespace std;

void quick_sort( vector<int> &arr , int low , int high){
    if( low >= high){
        return;
    }

    int start = low; 
    int end = high;
    int mid  = start + (end -start)/2;
    int pivot = arr[mid];

    while(start <= end){
        
    while(arr[start] < pivot){
        start++;
    }

    while(arr[end] > pivot){
        end--;
    }

    if(start<= end){
        swap(arr[start] , arr[end]);
        start++;
        end--;
    }
    }


    // now my pivot is my correct index now sort two halves

    quick_sort(arr,low,end);
    quick_sort(arr,start,high);
    
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 4, 7};
    quick_sort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
    cout << endl;
    // Output: 1 2 4 5 7 8
    return 0;
}
