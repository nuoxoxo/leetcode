class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>(*)(int, vector<vector<int>> &)> Solutions {
            GreedyBFS,
        };
        return Solutions[0](n, edges);
    }

    static vector<int> GreedyBFS (int N, vector<vector<int>> & edges) {

        if (N == 1)
            return {0};

        // Basic idea
        //  - finds the leaves of the tree iteratively,
        //  - until only the centroids remain ie. roots of the MHTs

        vector<int> res;
        unordered_map<int, vector<int>> ADJ;

        for (vector<int> & edge: edges) {
            int u = edge[0];
            int v = edge[1];
            ADJ[u].push_back(v);
            ADJ[v].push_back(u);
        }

        int /*long long*/ degrees[N];
        int i = -1;
        while (++i < N) {
            degrees[i] = ADJ[i].size();// 2147483648;
            if (degrees[i] == 1) {
                res.push_back(i);
                degrees[i]--;
            }
        }

        while (1) {
            // remove leaves until only the centroids ie. roots of MHTs remain
            //  - it is Greedy
            //  - reduce the tree's dimension in each iteration by removing leaves
            //  - once there are no new leaves, all there remains are centroids
            vector<int> new_leaves;
            for (int u: res) {
                for (int v: ADJ[u]) {
                    if (degrees[v] > 0) {
                        degrees[v]--;
                        if (degrees[v] == 1)
                            new_leaves.push_back(v);
                    }
                }
            }
            if (new_leaves.empty())
                break ;
            res = new_leaves;
        }
        return res;
    }
};
