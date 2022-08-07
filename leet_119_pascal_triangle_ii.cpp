class Solution {
public:
    vector<int> getRow(int row)
    {
        if (!row)
            return {1} ;
        if (row == 1)
            return {1, 1};

        vector<vector<int>> p(row + 1, vector<int>()) ;
        p[0] = {1} ;
        p[1] = {1, 1};
        int i = 1;
        while (++ i < row + 1)
        {
            int j = -1 ;
            while (++ j < i + 1)
            {
                if (!j || j == i)
                    p[i].push_back(1) ;
                else
                    p[i].push_back(p[i - 1][j - 1] + p[i - 1][j]) ;
            }
        }
        return (p[row]) ;
    }
};
