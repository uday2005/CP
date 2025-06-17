// 994. Rotting Oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0, minutes = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) ++fresh;
        vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty() && fresh) {
            int sz = q.size();
            while (sz--) {
                auto [i, j] = q.front(); q.pop();
                for (auto [di, dj] : dirs) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        q.push({ni, nj});
                        --fresh;
                    }
                }
            }
            ++minutes;
        }
        return fresh ? -1 : minutes;
    }
};