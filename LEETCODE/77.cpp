
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        function<void(int)> dfs = [&](int start) {
            if (comb.size() == k) {
                res.push_back(comb);
                return;
            }
            for (int i = start; i <= n; ++i) {
                comb.push_back(i);
                dfs(i + 1);
                comb.pop_back();
            }
        };
        dfs(1);
        return res;
    }
};