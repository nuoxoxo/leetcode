class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int         c = matrix[0].size();
        int         r = matrix.size() ;
        int         i, j ;
        vector<int> R(r, 1);
        vector<int> C(c, 1);

        i = -1;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
                if (!matrix[i][j])
                    R[i] = 0, C[j] = 0;
        }
        i = -1;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
                if (!R[i] || !C[j])
                    matrix[i][j] = 0 ;
        }
    }
};
