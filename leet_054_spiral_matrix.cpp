class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int         max_r = matrix.size(), max_c = matrix[0].size(), area;

        area = max_r * max_c;
        if (area == 1)
            return matrix[0] ;

        int         r, c, count, min_r, min_c ;
        vector<int> E ;

        min_r = min_c = -1 ; // bottom row, bottom col
        r = c = count = 0 ;
        while (1)
        {
            if (count)
                ++ c ;
            while (c < max_c)
            {
                E.push_back(matrix[r][c]);
                ++ c ;
                ++ count ;
            }
            if (count == area)
                break ;
            -- c ;
            ++ r ;
            while (r < max_r)
            {
                E.push_back(matrix[r][c]);
                ++ r ;
                ++ count ;
            }
            if (count == area)
                break ;
            -- r ;
            while (--c > min_c)
            {
                E.push_back(matrix[r][c]);
                ++ count ;
            }
            if (count == area)
                break ;
            ++ c ;
            -- max_r ;
            -- max_c ;
            ++ min_r ;
            ++ min_c ;
            while (--r > min_r)
            {
                E.push_back(matrix[r][c]);
                ++ count ;
            }
            if (count == area)  break ;
            ++ r ;
        }
        return E ;
    }
};
