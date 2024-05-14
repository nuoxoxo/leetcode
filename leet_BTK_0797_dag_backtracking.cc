class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<int> curr;
        vector<vector<int>> res;
        int Max = graph.size();

        std::function<void(int)> backtrack = [&](int node) {
            curr.push_back(node);

            if (node == Max - 1)
                res.push_back(curr);
            else for (int nxt: graph[node])
                backtrack(nxt);

            curr.pop_back();

        };
        backtrack(0);
        return res;
    }
};
