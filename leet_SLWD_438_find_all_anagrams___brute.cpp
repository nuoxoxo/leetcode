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

// static int x=[](){ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();

class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        std::array<int, 26> E{0} ;
        vector<int>         res ;
        int                 ls, lp, i, j;

        ls = s.length();
        lp = p.length();
        if (lp > ls)
            return res ;
        i = -1;
        while (++i < lp)
            E[p[i] - 'a']++;
        i = -1;
        while (++i < ls - lp + 1)
        {
            std::array<int, 26> tmp{0} ;

            j = -1;
            while (++j < lp)
                tmp[s[i + j] - 'a']++;
            if (E == tmp)
                res.push_back(i);
        }
        return res ;
    }
};
