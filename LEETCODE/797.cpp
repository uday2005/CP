
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            res.push_back(path);
        } else {
            for (int next : graph[node]) {
                dfs(graph, next, path);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(graph, 0, path);
        return res;
    }
};