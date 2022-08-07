class Solution {
public:
    bool searchMatrix(vector<vector<int>>& M, int target)
    {
        int i = 0;
        int j = M[0].size() - 1;
        while (i < M.size() && j > -1)
        {
            if (M[i][j] == target)
                return (true);
            else if (M[i][j] > target)
                j--;
            else if (M[i][j] < target)
                i++;
        }
        return (false);
    }
};
