class Solution {
public:

    int maximumSafenessFactor(vector<vector<int>>& grid)
    {
        int N = grid.size();
        assert (grid[0].size() == N);

        // setup

        deque<vector<int>> Q; // len-3 cells -> { r, c, score/dist }
        vector<vector<int>> safe(N, vector<int>(N, INT_MAX)); // all cells are safe
        vector<vector<bool>> SEEN(N, vector<bool>(N, false)); // all pos visited

        int r = -1, c;
        while (++r < N)
        {
            c = -1;
            while (++c < N)
            {
                if (grid[r][c]) // not safe
                {
                    Q.push_back( {r, c, 0} ); // todo a 1-cell
                    safe[r][c] = 0; // 1-cells are dangerous
                }
            }
        }

        // print(safe);

        // traverse n.1 - set safety level
        /*

        0 0 1
        0 0 0
        0 0 0 <--- for a grid like this

        2 1 0 
        3 2 1 
        4 3 2 <--- safety levels should be

        */

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!Q.empty())
        {
            auto node = Q.front();
            Q.pop_front();
            assert (node.size() == 3);
            r = node[0];
            c = node[1];
            int dis = node[2];
            // cout << r << ' ' << c << ' ' << dis << endl;
            int i = -1;
            while (++i < 4)
            {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if (rr < 0 || rr > N - 1 || cc < 0 || cc > N - 1 || safe[rr][cc] != INT_MAX)
                    continue ;
                safe[rr][cc] = dis + 1;
                Q.push_back({rr, cc, dis + 1});
            }
        }

        // print(safe);

        // traverse n.2 - find if path exists 

        assert(Q.empty());

        SEEN[0][0] = true;
        Q.push_back({0, 0, safe[0][0]}); // reset the beginning

        while (!Q.empty())
        {
            auto node = Q.front();
            r = node[0];
            c = node[1];
            int dis = node[2];
            if (r == N - 1 && c == N - 1)
                // return dis;
            {
                // print(safe);
                // cout << r << ' ' << c << ' ' << dis << "/here\n";
                return dis;
            }
            Q.pop_front();
            int i = -1;
            while (++i < 4)
            {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if (rr < 0 || rr > N - 1 || cc < 0 || cc > N - 1 || SEEN[rr][cc])
                    continue ;
                if (dis > safe[rr][cc])
                    Q.push_back({rr, cc, safe[rr][cc]});
                else Q.push_front({rr, cc, dis});
                SEEN[rr][cc] = true;
            }
        }
        assert (false);
    }

    void print(auto safe) {
        for (auto row: safe) {
            for (auto cell: row) cout << (cell == INT_MAX ? 1 : cell) << ' ';
            cout << '\n';
        }
        cout << endl;
    }

};
