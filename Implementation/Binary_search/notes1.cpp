#include <bits/stdc++.h>
using namespace std;
// when we want to insert at an index in an array such that it will not break its order of sorting then 
// then in the binary search we would insert it at the left position 

int searchInsert(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size()-1;
        

        while(left <= right){
            int mid = left + (right -left)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if( nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }

// so what binary sort does it finds only the one index that has value equal to its target.

// so when we have different values which are equal to the target how do we find multiple index.

// what  i thought is here and it was so wrong
vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> temp;
        sort(nums.begin() , nums.end());
        
        int left = 0; 
        int right = nums.size()-1;

       
        while(left <= right){
            int mid = left + (right -left)/2;
            if( nums[mid] >= target){
                right = mid - 1;
                temp.push_back(mid);
            }
            else{
                left = mid + 1;
            }
        }
        sort(temp.begin() , temp.end());
         return temp;
    }
    // The problem here any time we have value less than target it will push_back , that is not teh correct logic.

    // So to find the all index what we do is find min index whose value is equal to target and maxm index whose value is
    // is equal to the target.

    int Lower_bound(vector<int>& nums, int target){
        int lower_bound = -1;

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if( nums[mid] >= target){
                right = mid -1;
            }
            else{
                left = mid+ 1;
            }
        }

        if( left < nums.size() && nums[left] == target){
            lower_bound = left;
        }
        return lower_bound;
    }

    int Upper_bound(vector<int>& nums, int target){
        int upper_bound = -1;

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if( nums[mid] <=  target){
                left = mid + 1;
            }
            else{
                right = mid- 1;
            }
        }

        // why are we putting that down condition right < nums.size() is beacuse sometimes after exting the loop
        // left pointer goes equals to arr.size() and when we access it it will give run time error.
        if( right < nums.size() && nums[right] == target){
            upper_bound = right;
        }
        return upper_bound;
    }

    // so for that what we can do is push the index from lowerbound to upper bound both inclusive 
    // so all that index will have values equal to target

    int main(){
        vector<int> arr { 1, 2, 2,2, 3, 5};
        cout << Upper_bound(arr,2);
        cout << Lower_bound(arr,2);
    }

    #include <bits/stdc++.h>
using namespace std;

// returns the smallest number which is  number >= target
int ceiling(const vector<int> &arr, int target){

 
    int left = 0;
    int right = arr.size()-1;

    // If target is greater than the last element, no ceiling exists
    if (target > arr[right]) return -1; 
    while(left <= right){

        int mid = left + (right - left)/2;

        if( arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){ // look left 
            right = mid - 1;
        }
        else{
            left = mid + 1;  // look right
        }
    }
    return left;
}

// returns such that number  <= target 
int Floor(const vector<int> &arr, int target){
    int left = 0;
    int right = arr.size()-1;
    if( target  < arr[0]) return -1;
    while(left <= right){

        int mid = left + (right - left)/2;
        if( arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return right;
}

// so before end of the loop it will like ,
// if it find target in the loop returns it .
// if not then before ending of the loop it will go start <= ans (which is not in array)<= end so 
// after this start will go further like  end <= ans <= start 

int main(){

}