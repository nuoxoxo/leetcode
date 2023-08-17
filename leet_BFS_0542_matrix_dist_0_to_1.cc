class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& M)
    {
        if (!M.size())	return {} ;

        int                     i , j, x, y, R = M.size(), C = M[0].size();
        vector<int>		dx = {0, 1, 0, -1};
        vector<int>		dy = {-1, 0, 1, 0};
        vector<vector<int>>	D(R, vector<int>(C, -1));
        queue<pair<int, int>>	Q ;
        pair<int, int>		temp ;

        i = -1;
        while (++ i < R)
        {
            j = -1;
            while (++j < C)
            {
                if (!M[i][j])
                {
                    Q.push( {i, j} );
                    D[i][j] = 0;
                }
            }
        }
        while (!Q.empty())
        {
            temp = Q.front();
            Q.pop();
            i = -1;
            while (++i < 4)
            {
                x = temp.first + dx[i];
                y = temp.second + dy[i];
                if (x > -1 && y > -1 && x < R && y < C && M[x][y] == 1 && D[x][y] == -1)
                {
                    D[x][y] = D[temp.first][temp.second] + 1;
                    Q.push( {x, y} );
                }
            }
        }
        return D ;
    }
};
