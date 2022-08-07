class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        vector<vector<int>> p ;
        int                 c = matrix[0].size();
        int                 r = matrix.size();
        int                 i, j;

        i = -1 ;
        while (++i < r)
        {
            j = -1;
            while (++j < c) if (!matrix[i][j])  p.push_back({ i, j });
        }
        i = -1 ;
        while (++i < p.size())
        {
            j = -1;
            while (++j < c) matrix[ p[i][0] ][j] = 0 ;
            j = -1;
            while (++j < r) matrix[j][ p[i][1] ] = 0 ;
        }
    }
};
