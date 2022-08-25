/* ************************************************************************** */
/*                                                                            */
/*                            \\             /`/``                            */
/*                            ~\o o_       0 0\                               */
/*                            / \__)      (u  ); _  _                         */
/*                     / \/ \/  /           \  \/ \/ \                        */
/*                    /(   . . )            (         )\                      */
/*                   /  \_____/              \_______/  \                     */
/*                       []  []               [[] [[]    *.                   */
/*                       []] []]              [[] [[]                         */
/*                                                                            */
/* ****************************************************************** nuo *** */

class Solution {
public:
    bool canConstruct(string randomNote, string magazine)
    {
        vector<int> alpha(26, 0);
        int         i = -1;
        while (++i < randomNote.length())
            ++ alpha[randomNote[i] - 'a'] ;
        i = -1;
        while (++i < magazine.length())
            -- alpha[magazine[i] - 'a'] ;
        i = -1;
        while (++i < 26)
            if (alpha[i] > 0)
                return false ;
        return true ;
    }
};
