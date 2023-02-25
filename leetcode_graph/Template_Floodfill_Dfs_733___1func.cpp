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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int new_color)
    {
        if (image[i][j] == new_color)
		return image ;

        int old_color = image[i][j];
        int C = image[0].size();
        int R = image.size();

        // if (i < 0 || j < 0 || i > R - 1 || 
        //     j > C - 1 || new_color == old_color)
        //     return image ;

        image[i][j] = new_color;
        if (i < R - 1 && image[i + 1][j] == old_color)
            floodFill(image, i + 1, j, new_color);
        if (i > 0 && image[i - 1][j] == old_color)
            floodFill(image, i - 1, j, new_color);
        if (j < C - 1 && image[i][j + 1] == old_color)
            floodFill(image, i, j + 1, new_color);
        if (j > 0 && image[i][j - 1] == old_color)
            floodFill(image, i, j - 1, new_color);
        return image ;
    }
};
