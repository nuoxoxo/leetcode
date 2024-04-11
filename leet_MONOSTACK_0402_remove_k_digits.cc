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
    string removeKdigits(string num, int k)
    {
        string  s = "";
        int     i = -1;
        int     len = num.length();

        while (++i < len)
        {
            while(!s.empty() && s.back() > num[i] && k)
            {
                s.pop_back();
                k--;
            }
            s += num[i];
            // cout << s << endl;
        }

        while (!s.empty() && k) // in case k is not down to 0
        {
            s.pop_back();
            k--;
        }
        i = 0;
        while (s[i] == '0')
            i++;
        // cout << i << ' ' << s << endl;

        if (len <= i)   return "0";
        while (i > 0)   s.erase(0, 1), i--;
        // cout << s << endl;

        return s == "" ? "0" : s ;
    }
};
