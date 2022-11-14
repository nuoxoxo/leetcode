class Solution {
public:
    int removeStones(vector<vector<int>> & stones)
    {
	int		i = -1;
        int             res = 0;
	int		n = stones.size();
        vector<bool>    v(n, 0);

        while (++i < n)
        {
            if ( !v[i])
            {
                res++;
                dfs(stones, v, i);
            }
        }
        return n - res;
    }

    void dfs(vector<vector<int>> & stones, vector<bool> & v, int index)
    {
        int     n = stones.size();
        int     i = -1;

        v[index] = true;
        while (++i < n)
        {
            if ( !v[i] && (stones[i][0] == stones[index][0]
				    || stones[i][1] == stones[index][1]))
            {
                dfs(stones, v, i);
            }
        }
    }
};
