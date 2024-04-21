class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<bool(*)(int, vector<vector<int>>&, int, int)> Solutions {
            BFS,
        };
        return Solutions[0](n, edges, source, destination);
    }

    static bool BFS (int n, vector<vector<int>>& edges, int source, int destination)
    {
        (void) n;
        set<int> Seen;
        Seen.insert(source);
        deque<int> Q;
        Q.push_back(source);
        unordered_map<int, vector<int>> ADJ;
        // prepare adjacency list
        for (auto & edge : edges) {
            int u = edge[0];
            int v = edge[1];
            ADJ[u].push_back(v);
            ADJ[v].push_back(u);
        }
        while (!Q.empty()) {
            int u = Q.front();
            if (u == destination)
                return true;
            Q.pop_front();
            for (int v : ADJ[u]) {
                if (Seen.find(v) == Seen.end()) {
                    Seen.insert(v);
                    Q.push_back(v);
                }
            }
        }
        return false;
    }
};
