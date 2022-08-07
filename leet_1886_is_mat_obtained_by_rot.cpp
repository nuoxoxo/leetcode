class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar)
    {
        if (tar == mat)
            return true ;
        int n = mat.size(), t = 0, i = -1, j ;
        while (++t < 4)
        {
            reverse(mat.begin(), mat.end());
            i = -1;
            while (++i < n)
            {
                j = i;
                while (++j < n)
                    swap(mat[i][j], mat[j][i]);
            }
            if (mat == tar)
                return true ;
        }
        return false ;
    }
};
