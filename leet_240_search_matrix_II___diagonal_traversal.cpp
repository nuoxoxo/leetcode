class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int c = matrix[0].size();
        int r = matrix.size();
        int j = c - 1;
        int i = 0;
        while (i < r && j > -1)
        {
            int val = matrix[i][j];
            if (val == target)
                return true ;
            else if (val < target)
                ++ i;
            else
                -- j;
        }
        return false ;
    }
};
