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
    string  reverseVowels(string s)
    {
            vector<int> v;
            int         size, i;

            i = -1;
            while (++i < s.length())
            {
                if (isVowel(s[i]))
                    v.push_back(i);
            }
            size = v.size();
            if (!size || size == 1)
                return (s);
            i = -1;
            while (++i < size / 2)
            {
                swap(s[ v[i] ], s[ v[size - 1 - i] ]);
            }
            return (s);
    }
    
    bool    isVowel(char c)
    {
            if (c == 'a' || c == 'A' || c == 'e' || c == 'E' ||
                c == 'i' || c == 'I' || c == 'o' || c == 'O' ||
                c == 'u' || c == 'U')
                return (true);
            return (false);
    }
};
