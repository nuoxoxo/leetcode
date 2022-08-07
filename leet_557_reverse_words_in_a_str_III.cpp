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
            string  tmp, res;
            int     i = 0;

            while (i < s.length())
            {
                if (isspace(s[i]))
                    res += s[i++];
                else
                {
                    stringstream(s.substr(i, s.length() - i)) >> tmp;
                    i += tmp.length();
                    res += rev(tmp);
                }
            }
            return (res);
    }
    
    string  rev(string s)
    {
            int len = s.length();
            int i = -1;

            while ( ++i < len / 2 )
                swap(s[i], s[len - 1 - i]);
            return (s);
    }
};
