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
    bool isPalindrome(string s)
    {
        if (s == "")    return true ;

        string  ss = "" ;
        int     i = -1;

        while (++i < s.length())
        {
            if (s[i] <= 'Z' && s[i] >= 'A')
                ss += s[i] + 32;
            if (s[i] <= 'z' && s[i] >= 'a')
                ss += s[i] ;
            if (s[i] <= '9' && s[i] >= '0')
                ss += s[i] ;
        }
        return wordIsPalindrome(ss);
    }

    bool wordIsPalindrome(string s)
    {
        if (s == "")
            return true ;
        int n = s.length();
        int i = -1;

        while (++i <= L / 2)
        {
            if (s[i] != s[n - 1 - i])
                return false ;
        }
        return true ;
    }
};
