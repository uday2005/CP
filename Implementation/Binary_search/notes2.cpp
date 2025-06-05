#include <bits/stdc++.h>
using namespace std;

// find position of element in a sorted array infinite
// so array is infinte of size so we can't use teh size method.

// we can't use the arr.size()

// so the approach will be find the first index and last index in between which will contain the target.


// How do we find the first and the last index .
// one idea is to take chunk and apply the binary_seacrh in that and when we didn't find it .
// we can increase the size exponentially and again do binary_search and again find .

// 1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 64 .


int binary_search(vector<int> &arr,int target , int start, int end){

    while(start <= end){

        int mid = start+ (end- start)/2;

        if(target < arr[mid]){
            end = mid -1;
        }
        else if ( target > arr[mid]){
            start = mid + 1;
        }
        else{
            return mid;
        }
    }
}

int finding_range(vector<int> arr, int target){
    // first find the range

    // first start with box of size 2

    int start = 0;
    int end = 1;

    while(target > arr[end]){
        int newStart = end + 1;

        // end will go twice the box size
        // end = end + 2 * (end - start + 1)

        end  = end + 2 *(end - start+1);

        start = newStart;
    }

}