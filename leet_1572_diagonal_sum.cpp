class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        int r = mat.size(); 
        if (r == 1) return mat[0][0];

        int res = 0, i = -1, j;
        while (++i < r)
        {
            j = -1;
            while (++j < r)
                if (j == i || j == r - 1 - i)
                    res += mat[i][j];
        }
        return res ;
    }
};
