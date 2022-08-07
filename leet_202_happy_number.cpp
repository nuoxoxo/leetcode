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
    bool isHappy(int n)
    {
        set<int>    E;

        while (1)
        {
            n = makeHappy(n);
            if (n == 1) break;
            if (find(E.begin(), E.end(), n) != E.end())
                return false ;
            E.insert(n);
        }
        return true ;
    }
    
    int makeHappy(int n)
    {
        int tmp, tt;

        tt = 0;
        while (n)
        {
            tmp = (n % 10) * (n % 10);
            tt += tmp;
            n /= 10;
        }
        return tt ;
    }
};
