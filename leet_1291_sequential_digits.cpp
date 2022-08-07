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
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> E;
        int         i, j, n, num;

        n = 1;
        while (++n < 11)
        {
            i = 0;
            while (++i < 11 - n)
            {
                j = -1;
                num = 0;
                while (++j < n) num = num * 10 + i + j;
                if (num < high + 1 && num > low - 1)
                    E.push_back(num) ;
            }
        }
        return E ;
    }
};
