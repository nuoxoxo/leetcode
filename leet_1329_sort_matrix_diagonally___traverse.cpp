class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& G)
    {
        /*
         * small problem 1: how to traverse diagonally
         *
         * diff = i - j
         * (0, 0), (1, 1), (2, 2), ... diff = 0
         * (0, 1), (1, 2), (2, 3), ... diff = -1
         * (0, 2), (1, 3), (2, _) (j out of bound), ... diff = -2
         * (1, 0), (2, 1), ... diff = 1
         *
         * lower bound of diff: 1 - C  when i = 0, j = C - 1
         * upper bound of diff: R - 1   when i = R - 1, j = 0
         *
         * -
         *
         * small question 2: there's no more problem
	 *
	 * we use the diff to travers the diagonal axis, 
         * on every diagonal axis, grab all elements, sort them
         * once sorted, they are put in-place in res
         *
         */

        int c = G[0].size(), r = G.size();
        vector<vector<int>> res(r, vector<int>(c, 0));
        int i, j, d, t;

        d = c * (-1);
        while (++d < r)
        {
            vector<int>     temp;

            i = -1;
            while (++i < r)
            {
                j = i - d;
                if (j < c && j > -1)
                    temp.push_back(G[i][j]);
            }
            sort(temp.begin(), temp.end());
            i = -1;
            t = 0;
            while (++i < r)
            {
                j = i - d;
                if (j < c && j > -1)
                    res[i][j] = temp[t++];
            }
        }
        return res;
    }
};
