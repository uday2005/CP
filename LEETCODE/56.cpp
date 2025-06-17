class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b){
        //     return a[1] < b[1]; //sort in increasing order of end interval
        // });
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            int n = res.size();
            int currSt = intervals[i][0];
            if(currSt <= res[n - 1][1]){
                res[n - 1][1] = max(res[n - 1][1], intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};