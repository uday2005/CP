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

    // now do the binry search in the deefinde range.

    return binary_search(arr,target , start ,end);

}

// Now one more type of question that come up is that bi tonic array
// like first it will increase then it will decrease 

// Now we have to find the max peak index.

// Like the bitonic array
// it will find the peak element index.

int findPeakElement(vector<int>& nums) {
        int n = nums.size()-1;
        int l = 0;
        int r = n;
        while(l < r){

            int mid = l + (r-l)/2;

            if(nums[mid+1] > nums[mid]){
                l = mid+1;  
            }
            else{
                // This may be the answer that's why we are not saying mid -1
                r = mid;
            }
            
        }
        return l;
}

// If the array is in decreasing order sorted still we can use the binary search

int binary_search_dec(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


// Anouther way of implementing the binary search is

vector<int> arr;
bool ok(int k) {
    return arr[k];
}
// [f,f,t,t,t]

int main(){
int n = 100;
int z = n - 1; // n is the array size
int x = -1;
for (int b = z; b >= 1; b /= 2) {
    while (x + b < n && !ok(x + b)) x += b;
}
int k = x + 1; // First index where arr[k] is true
}


