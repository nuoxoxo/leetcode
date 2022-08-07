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
    int findMinArrowShots(vector<vector<int>>& P)
    {
        int L, Uf, Ue, Df, De, i, count;

        L = (int) P.size();
        sort(P.begin(), P.end());
        Uf = P[0][0];
        Ue = P[0][1];
        i = 0;
        count = 1;
        while (++i < L){
            Df = P[i][0];
            De = P[i][1];
            if (Df <= Ue)
            {
                Uf = Uf > Df ? Uf : Df;
                Ue = Ue < De ? Ue : De;
            }
            else {
                Uf = Df;
                Ue = De;
                ++ count ;
            }
        }
        return count ;
    }
};
