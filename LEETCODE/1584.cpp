
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);
        minDist[0] = 0;
        for (int i = 0; i < n; ++i) {
            int u = -1;
            for (int v = 0; v < n; ++v)
                if (!inMST[v] && (u == -1 || minDist[v] < minDist[u]))
                    u = v;
            res += minDist[u];
            inMST[u] = true;
            for (int v = 0; v < n; ++v)
                if (!inMST[v])
                    minDist[v] = min(minDist[v], abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]));
        }
        return res;
    }
};