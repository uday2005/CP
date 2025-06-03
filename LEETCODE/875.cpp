#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int val = 0;
        int high = *max_element(piles.begin() , piles.end());
        int i = 1;
        while(i <= high){
            int total_time = 0;
            for(auto pile : piles){
                total_time += (pile/i) + (pile %i != 0);
            }

            if(total_time > h){
                i++;
            }
            else{
                val = i;
                break;
            }
        }
        return val;
    }
};

// this approach will go as the quadratic time which is very inefficient.

// No we try this by binary search



class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int val = 0;
        ll high = *max_element(piles.begin() , piles.end());
        ll i = 1;
        
        while(i <= high){
            ll  mid = i + (high -i)/2;
            ll total_time = 0;

            for(auto pile : piles){
                total_time += (pile/mid) + (pile %mid != 0);
            }

            if(total_time <= h){
                val = mid;
                high = mid -1;
            }
            else{
                high = mid + 1;
            }
            
        }
        return val;
    }
};


