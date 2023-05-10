class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i = 0, j = 0, d = 0;
        int limit = n * n + 1;
        int count = 1;
        while (1)
        {
            while (j < n - d)  // top row
            {
                res[i][j] = count++;
                ++j;
            }
            if (count == limit)
                break;
            j -= 1;
            i += 1;
            while (i < n - d)  // right col
            {
                res[i][j] = count++;
                ++i;
            }
            if (count == limit)
                break;
            i -= 1;
            j -= 1;
            while (j > d - 1)   // bottom row
            {
                res[i][j] = count++;
                --j;
            }
            if (count == limit)
                break;
            i -= 1;
            j += 1;
            d += 1; // update bound at end of each cycle

            while (i > d - 1)  // left col
            {
                res[i][j] = count++;
                --i;
            }
            if (count == limit)
                break;
            i += 1;
            j += 1;
        }
        return res;
    }
};
