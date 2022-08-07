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
    string reverseStr(string s, int k)
    {
        int         len, i, j;
        string      res;

        len = s.length();
        if ( k >= len )
            return (rev(s));
        i = 0;
        while (i < len)
        {
            if (i + k > len)
            {
                    res += rev(s.substr(i, len - i));
                    break;
            }
            else
                res += rev(s.substr(i, k));
            i += k;
            if (i + k > len)
            {
                    res += s.substr(i, len - i);
                    break;
            }
            else
                res += s.substr(i, k);
            i += k;
        }
        return (res);
    }
    
    string rev(string s)
    {
        char    c;
        int     len, i;

        i = -1;
        len = s.length();
        while ( ++i < len / 2 )
            swap(s[i], s[len - 1 - i]);
        return (s);
    }
};
