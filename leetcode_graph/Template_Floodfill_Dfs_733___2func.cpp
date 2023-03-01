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

    void DFS(vector<vector<int>> &image, vector<vector<bool>>& drown, int x, int y, int ocl, int ncl)
    {
        int     cols = image[0].size();
        int     rows = image.size();

        if (x < 0 || y < 0 || x > rows - 1 || y > cols - 1 ||
            image[x][y] != ocl || drown[x][y])
            return ;
        drown[x][y] = true;
        image[x][y] = ncl;
        DFS(image, drown, x + 1, y, ocl, ncl);
        DFS(image, drown, x - 1, y, ocl, ncl);
        DFS(image, drown, x, y + 1, ocl, ncl);
        DFS(image, drown, x, y - 1, ocl, ncl);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int                     oldColor = image[sr][sc];
        int                     rows = image.size();
        int                     cols = image[0].size();
        vector<vector<bool>>    drown(rows, vector<bool> (cols, false));

        DFS(image, drown, sr, sc, oldColor, newColor);

        return (image);
    }

};
