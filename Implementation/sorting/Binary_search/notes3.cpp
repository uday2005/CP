#include <bits/stdc++.h>
using namespace std;

// This will not work for duplicate value
int pivot_rbs(vector<int> &arr){
    int start = 0;
    int end = arr.size()-1;

    while(start <= end){

        int mid = start + (end - start )/2;

        

        if(mid < end && arr[mid] > arr[mid+1]){
            return mid;
        }
        if(mid > start && arr[mid]  < arr[mid-1]){
            return mid-1;
        }

        if(arr[start]  >= arr[mid]){
            end  = mid -1; // if the left side will be smaller then the right side  index value  will be larger
        }
        else{
            start = mid +1; // if the left side will be larger than the right side  index value will be larger
        }

    }
    return -1;
}

// What we will do if we have duplicates

int pivot_rbs_dup(vector<int> &arr){
    int start = 0;
    int end = arr.size()-1;

    while(start <= end){

        int mid = start + (end - start )/2;

        

        if(mid < end && arr[mid] > arr[mid+1]){
            return mid;
        }
        if(mid > start && arr[mid]  < arr[mid-1]){
            return mid-1;
        }

        // if elemnents at start , middle and end ar eequal just skip the duplicates.

        if(arr[start] == arr[mid] && arr[end] == arr[mid]){

            // check first start is pivot

            if(arr[start] > arr[start + 1]){
                return start ;
            }
            start ++;

            // check whether end is pivot

              if(arr[end]  < arr[end-1]){
                return end -1 ;
            }
            end --;

        }


        if(arr[start]  >= arr[mid]){
            end  = mid -1; // if the left side will be smaller then the right side  index value  will be larger
        }
        else{
            start = mid +1; // if the left side will be larger than the right side  index value will be larger
        }

    }
    return -1;
}
