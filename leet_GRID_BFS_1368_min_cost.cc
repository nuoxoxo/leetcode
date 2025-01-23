class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
        dist[0][0] = 0;
        vector<tuple<int,int,int>> D = { // tuple
            {1,0,1},
            {2,0,-1},
            {3,1,0},
            {4,-1,0},
        };
        deque<pair<int,int>> Q = {{0,0}};
        while (!Q.empty()){
            auto [r,c] = Q.front();
            Q.pop_front();
            for (auto [d,dr,dc]: D){
                int rr = r + dr, cc = c + dc;
                if (-1 < rr && rr < R && -1 < cc && cc < C){
                    int cost = d == grid[r][c] ? 0 : 1;
                    int tt = cost + dist[r][c];
                    if (dist[rr][cc] > tt){
                        dist[rr][cc] = tt;
                        Q.push_back({rr,cc});
                    }
                } 
            }
        }
        return dist[R - 1][C - 1];
    }
};
