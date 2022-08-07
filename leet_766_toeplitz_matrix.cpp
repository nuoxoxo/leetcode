class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        vector<int> standard = matrix[0];
        int         n = matrix[0].size();
        int         m = matrix.size();
        int         i = 0;

        if (m == 1 || n == 1)   return true ;
        while (++i < m)
        {
            vector<int> current = matrix[i];
            standard.pop_back();
            if (!std::equal(standard.begin(), standard.end(), current.begin() + 1))
                return false ;
            standard = current;
        }
        return true ;
    }
};
