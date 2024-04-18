class Solution {
public:
    #define vvi vector<vector<int>>
    int islandPerimeter(vector<vector<int>>& grid)
    {
        vector<int(*)(vvi &)> Solutions {
            // Bruteforce_iterative,
            // Bruteforce_recursive,
            Math,
        };
        return Solutions[0](grid);
    }

    /// all 3 solns are O(R * C)

    static int Math(vvi & G)
    {
        int R = G.size();
        int C = G[0].size();
        int res = 0;
        int r = -1, c;
        while (++r < R) {
            c = -1;
            while (++c < C) {
                if (G[r][c]) {
                    res += 4;
                    if (r > 0 && G[r - 1][c] == 1) {
                        res -= 2;
                    }
                    // cut a shared edge ie. minus 1 for each of the 2 adjacent squares
                    if (c > 0 && G[r][c - 1] == 1) {
                        res -= 2;
                    }
                }
            }
        }
        return res;
    }

    static int Bruteforce_recursive(vvi & G)
    {
        std::function<int(vvi &, int, int)> hasOneNeighbor = [&](vvi & G, int r, int c)
        {
            int R = G.size(), C = G[0].size();
            if (r == R || r < 0 || c == C || c < 0 || G[r][c] == 0)
                return 0;
            return 1;
        };

        std::function<int(vvi &, int, int)> countNeighbors = [&](vvi & G, int r, int c)
        {
            int neigs = hasOneNeighbor(G, r + 1, c) \
                + hasOneNeighbor(G, r - 1, c) \
                + hasOneNeighbor(G, r, c + 1) \
                + hasOneNeighbor(G, r, c - 1);
            return 4 - neigs;
        };

        int R = G.size();
        int C = G[0].size();
        int res = 0;
        int r = -1, c;
        while (++r < R) {
            c = -1;
            while (++c < C) {
                if (G[r][c] == 1)
                    res += countNeighbors(G, r, c);
            }
        }
        return res;
    }

    static int Bruteforce_iterative(vvi& G)
    {
        int dr[4] = {1,0,-1, 0};
        int dc[4] = {0,1, 0,-1};
        int R = G.size();
        int C = G[0].size();
        int res = 0;
        int r = -1, c;
        while (++r < R) {
            c = -1;
            while (++c < C) {
                if (G[r][c]) {
                    int i = -1;
                    while (++i < 4) {
                        int rr = r + dr[i];
                        int cc = c + dc[i];
                        if (rr == R || rr < 0 || cc == C || cc < 0 || G[rr][cc] == 0)
                            res++;
                    }
                }
            }
        }
        return res;
    }
};
