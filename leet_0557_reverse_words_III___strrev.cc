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
    string  reverseWords(string s)
    {
            int     L, R, len;

            L = R = 0;
            len = s.length();
            while (R < len)
            {
                if (s[R] == ' ')
                {
                    rev(s, L, -- R);
                    L = ++R + 1;
                }
                ++R;
            }
            rev(s, L, len - 1);
            return (s);
    }
    
    void    rev(string &s, int L, int R)
    {
            while (!(L > R))
            {
                swap(s[L], s[R]);
                ++L;
                --R;
            }
    }
};
