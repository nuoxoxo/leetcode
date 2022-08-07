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

    bool    checkInclusion(string s1, string s2)
    {
        string          s;
        int             len1, len2, i, j;
        
        len1 = s1.length();
        len2 = s2.length();
        if (len2 < len1)
            return (false);
        i = 0;
        while (i < len2 - len1 + 1)
        {
            s = s2.substr(i, len1);
            if (is_permutation(s.begin(), s.end(), s1.begin()))
                return (true);
            i++;
        }
        return (false);
    }

};
