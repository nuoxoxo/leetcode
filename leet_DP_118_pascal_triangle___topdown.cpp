class Solution {
public:
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> p(n, vector<int>()) ;

        p[0] = {1} ;
        if (n == 1)
            return (p);
        p[1] = {1, 1} ;
        if (n == 2)
            return (p);
        
        int i = 1, j ;

        while (++i < n)
        {
            j = -1;
            while (++j < i + 1)
            {
                if (!j || j == i)
                    p[i].push_back(1);
                else
                    p[i].push_back(p[i - 1][j - 1] + p[i - 1][j]);
            }
        }
        return p ;
    }
};
