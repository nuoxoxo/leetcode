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
#define vvi vector<vector<int>>
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s)
    {
        int i, j, hi, lo;
        vvi res ;

        i = j = 0;
        while (i < f.size() && j < s.size())
        {
            lo = max(f[i][0], s[j][0]);
            hi = min(f[i][1], s[j][1]);
            if (lo <= hi)
                res.push_back( {lo, hi} );
            if (f[i][1] < s[j][1])
                i++;
            else
                j++;
        }
        return res ;
    }
};
