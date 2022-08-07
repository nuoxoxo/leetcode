class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
    {
        int co = mat[0].size() ;

        if (r * c ^ (co * mat.size()))  return mat ;

        vector<vector<int>> E(r, vector<int>(c));
        int                 i = -1;

        while (++i < r * c) E[i / c][i % c] = mat[i / co][i % co];
        return E ;
    }
};
