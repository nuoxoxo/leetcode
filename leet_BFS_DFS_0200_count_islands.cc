class Solution {
public:
    #define vvc vector<vector<char>>
    int numIslands(vector<vector<char>>& grid) {
        vector<int(*)(vvc &)> Solutions {
            // Floodfill,
            BFS,
        };
        return Solutions[0](grid);
    }

    static int BFS(vvc & G)
    {
        int R = G.size();
        int C = G[0].size();
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        set<pair<int, int>> Seen;
        deque<pair<int, int>> Q;
        int res = 0;
        int r = -1;
        while (++r < R)
        {
            int c = -1;
            while (++c < C)
            {
                if (G[r][c] == '1' and Seen.find({r, c}) == Seen.end())
                {
                    res++;
                    Seen.insert({r, c});
                    Q.push_back({r, c});
                    while (!Q.empty())
                    {
                        auto node = Q.front();
                        Q.pop_front();
                        int i = -1;
                        while (++i < 4)
                        {
                            int rr = node.first + dr[i];
                            int cc = node.second + dc[i];
                            if (-1 < rr && rr < R && -1 < cc \
                            && cc < C && G[rr][cc] == '1' \
                            && Seen.find({rr, cc}) == Seen.end())
                            {
                                Q.push_back({rr, cc});
                                Seen.insert({rr, cc});
                            }
                        }
                    }
                }
            }
        }
        return res;
    }

    static int Floodfill (vvc & G) {
        int R = G.size();
        int C = G[0].size();
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        std::function<void(vvc &, int, int) > Flood = [&](vvc& G, int r, int c) {
            if (r < 0 || r > R - 1 || c < 0 || c > C - 1 || G[r][c] != '1') 
                return ;
            G[r][c] = '0';
            int i = -1;
            while (++i < 4) 
                Flood(G, r + dr[i], c + dc[i]);
        };
        int res = 0;
        int r = -1;
        while (++r < R) {
            int c = -1;
            while (++c < C) {
                if (G[r][c] == '1') {
                    res++;
                    Flood(G, r, c);
                }
            }
        }
        return res;
    }
};
