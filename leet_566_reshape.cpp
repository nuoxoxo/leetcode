/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
    {
        int             i, j, k;
        int             h = mat.size();
        int             w = mat[0].size();
        vector<int>     temp;
        
        if (r * c != h * w)
            return (mat);
        
        vector<vector<int>> rest(r, vector<int> (c, 0));

        i = -1;
        while (++i < h)
        {
            j = -1;
            while (++j < w)
                temp.push_back(mat[i][j]);
        }
        k = i = -1;
        while (++i < r)
        {
            j = -1;
            while (++j < c)
                rest[i][j] = temp[++k];
        }
        
        return (rest);
    }
};
