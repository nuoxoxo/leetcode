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
    int     minCostToMoveChips(vector<int>& pos)
    {
            int     i, eve, odd;
            
            eve = odd = 0;
            i = -1;
            while (++i < pos.size())
            {
                if (pos[i] % 2)
                    ++odd;
                else
                    ++eve;
            }

            return (eve = eve < odd ? eve : odd);
    }
};
