class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<int> rowsums(R,0), colsums(C, 0);
        int r = -1, c;
        while (++r < R){
            c = -1;
            while (++c < C) {
                int v = grid[r][c];
                rowsums[r] += v;
                colsums[c] += v;
            }
        }
        // for (auto l: rowsums) cout << l << endl;
        // for (auto l: colsums) cout << l << endl;
        r = -1;
        int res = 0;
        while (++r < R){
            c = -1;
            while (++c < C)
                res += grid[r][c] && rowsums[r] + colsums[c] > 2;
        }
        return res;
    }
};
