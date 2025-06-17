class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] + b[1] < b[0] + a[1];
    }
    int minimumEffort(vector<vector<int>>& tasks) { 
        sort(tasks.begin(), tasks.end(), cmp);
        long long res = -1e10;
        long long ps = 0;
        for(int i = 0; i < tasks.size(); i++){
            res = max(res, ps + tasks[i][1]);
            ps +=tasks[i][0];   
        }
        return res;
    }

};