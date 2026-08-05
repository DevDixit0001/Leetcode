class Solution {
public:
    int count = 0;
    int hh = 0;
    void helpsus(int node, vector<int>& vis, vector<vector<int>>& graph) {
        if (vis[node] == -1)
            return;
        vis[node] = -1;
        count++;
        for (auto it : graph[node]) {
            helpsus(it, vis, graph);
        }
    }
    void add(int node, vector<int>& vis, vector<vector<int>>& graph,
             vector<int>& ans) {
        vis[node] = 1;
        ans.push_back(node);
        hh++;
        for (auto it : graph[node]) {
            if (vis[it] == 0 || vis[it] == -1)
                add(it, vis, graph, ans);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {
        vector<vector<int>> graph(n);
        for (auto it : in) {
            graph[it[0]].push_back(it[1]);
        }
        vector<int> vis(n, 0);

        helpsus(k, vis, graph);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                add(i, vis, graph, ans);
            }
        }
        if (count != n - hh) {
            vector<int> g(n);
            for (int i = 0; i < n; i++)
                g[i] = i;
            return g;
        }
        return ans;
    }
};