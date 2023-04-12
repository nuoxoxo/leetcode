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
    int mySqrt(int x)
    {
        long    tmp, res, mp;
        int     L, R;

        mp = x / 2;
        L = 0;
        R = x;
        while (L <= R)
        {
            tmp = mp * mp;
            if (tmp == x)
                return mp ;
            if (tmp > x)
                R = mp - 1;
            if (tmp < x)
            {
                res = mp;
                L = mp + 1;
            }
            mp = (R - L) / 2 + L ;
        }
        return res ;
    }
};
