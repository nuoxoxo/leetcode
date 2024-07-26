class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        /*
        distanceThreshold = 4
           (0)
            |
           3|
            |
           (1)
           / \
         1/   \4
         /     \
        (2)----(3)
            1
        city 0: 0-1/cost 3, 0-2/cost 3+1
        city 1: 1-0/cost 3, 1-2/cost 1, 1-3/cost 4
        city 2: 2-0/cost 1+3, 2-1/cost 1, 2-3/cost 1
        city 3: 3-1/cost 4, 3-2/cost 1
             ^ return 3 coz 3>0
        */

        vector<int(*)(int, vector<vector<int>> &, int)> Solutions = {
            Floyd_Warshall_DP,
            Dijkstra,
        };
        return Solutions[0](n, edges, distanceThreshold);
    }

    static int Dijkstra(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        unordered_map<int, vector<pair<int, int>>> weight_dest;
        for (auto & edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            weight_dest[u].push_back({w, v});
            weight_dest[v].push_back({w, u});
        }

        std::function<int(int)> dijkstra = [&](int node){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
            heap.push({0, node});
            set<int> seen;
            while (!heap.empty())
            {
                auto & curr_wd = heap.top();
                int curr_weight = curr_wd.first;
                int curr_node = curr_wd.second;
                heap.pop();

                if (seen.find(curr_node) == end(seen))
                {
                    seen.insert(curr_node);
                    for (auto & next_wd : weight_dest[curr_node])
                    {
                        int next_weight = next_wd.first;
                        int next_node = next_wd.second;
                        int tt_weight = curr_weight + next_weight;
                        if (tt_weight <= distanceThreshold)
                            heap.push({tt_weight, next_node});
                    }
                }
            }
            return seen.size() - 1;
        };

        int res = -1;
        int min_reachables = n;
        int u = -1;
        while (++u < n)
        {
            int reachables = dijkstra(u);
            if (reachables <= min_reachables)
            {
                res = u;
                min_reachables = reachables;
            }
        }
        return res;
    }

    static int Floyd_Warshall_DP(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        // Floyd-Warshall - DP

        vector<vector<int>> W(n, vector<int>(n, (int)1e6/*INT_MAX*/));
        // 1e6, because
        //  max(n) = 100, max(weight) = 1e4 ---> max(each cell) = 1e6
        int i = -1;
        while (++i < n)
            W[i][i] = 0; // dist=0 if we dont move
        for (auto & edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            W[u][v] = w; // bi-directional dist=same
            W[v][u] = w;
        }
        // Floyd-Warshall DP idea:
        //  exhaust all possible intermediate-cities in range(N)
        int d = -1;
        while (++d < n)
        {
            int u = -1;
            while (++u < n)
            {
                int v = -1;
                while (++v < n)
                    if (W[u][v] > W[u][d] + W[d][v])
                        W[u][v] = W[u][d] + W[d][v];
            }
        }

        int res = -1;
        int min_reachables = n;
        int u = -1;
        while (++u < n)
        {
            int reachables = 0;
            int v = -1;
            while (++v < n)
                if (W[u][v] <= distanceThreshold)
                    ++reachables;
            if (min_reachables >= reachables)
            {
                // cout << "u/ " << u << cout << " dist/ " << reachables << endl;;
                min_reachables = reachables;
                res = u;
            }
        }

        return res;
    }
};
/*
4
[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]
4
5
[[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]]
2
5
[[0,1,2],[0,4,8],[1,2,10000],[1,4,2],[2,3,10000],[3,4,1]]
10000
*/
