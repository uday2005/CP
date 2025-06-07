#include<bits/stdc++.h>
using namespace std;

void two_way_partion( vector<int> &arr , int low , int high, int& start , int& end){
    if( low >= high){
        return;
    }

     start = low; 
     end = high;
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

}


// Three-way partition: rearranges array so that
// arr[low..lt-1] < pivot, arr[lt..gt] == pivot, arr[gt+1..high] > pivot
pair<int, int> threeWayPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[low + (high - low) / 2]; // or any pivot selection
    int lt = low, gt = high, i = low;
    while (i <= gt) {
        if (arr[i] < pivot) {
            swap(arr[lt], arr[i]);
            lt++;
            i++;
        } else if (arr[i] > pivot) {
            swap(arr[i], arr[gt]);
            gt--;
        } else {
            i++;
        }
    }
    return {lt, gt};
}

void quickSortThreeWay(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    pair<int, int> p = threeWayPartition(arr, low, high);
    int lt = p.first;
    int gt = p.second;
    quickSortThreeWay(arr, low, lt - 1); // Sort left part
    quickSortThreeWay(arr, gt + 1, high); // Sort right part
}

// Example usage:
int main() {
    vector<int> arr = {2, 1, 2, 4, 2, 3, 5, 1};
    quickSortThreeWay(arr, 0, arr.size() - 1);
    // arr is now sorted
    return 0;
}
