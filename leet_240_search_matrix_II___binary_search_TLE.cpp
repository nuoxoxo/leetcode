class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int     r = matrix.size();
        int     c = matrix[0].size();
        int     i = -1;
        int     L, mid, val, R;

        while (++i < r)
        {
            L = 0;
            R = c - 1;
            while (L <= R)
            {
                mid = (L + R) / 2;
                val = matrix[i][mid];
                if (val < target)
                    L++;
                else if (val > target)
                    R--;
                else
                    return true;
            }
        }
        return false;
    }
};
