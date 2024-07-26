class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
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
        //  incl. non-existant ones 
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
        int min_reachables = INT_MAX;
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
