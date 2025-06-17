
class Solution {
public:
    int find(vector<int>& p, int x) {
        return p[x] == x ? x : p[x] = find(p, p[x]);
    }
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        vector<int> parent(n+1);
        iota(parent.begin(), parent.end(), 0);
        int res = 0, count = 0;
        for (auto& c : connections) {
            int u = find(parent, c[0]), v = find(parent, c[1]);
            if (u != v) {
                parent[u] = v;
                res += c[2];
                if (++count == n-1) return res;
            }
        }
        return -1;
    }
};