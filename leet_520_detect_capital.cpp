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

//  Solve 1 : ultimate iterative bf

class Solution {
public:
    bool detectCapitalUse(string s) {
        int i;

        i = 0;
        while (++i < s.length())
            if ((isupper(s[1]) != isupper(s[i])) || (islower(s[0]) && isupper(s[i])))
                return false ;
        return true ;
    }
};

//  Solution 2 : shorter bf

/*

class Solution {
public:
    bool detectCapitalUse(string s)
    {
        if (s.size() < 2) return true ;

        int len = s.size(), i;

        if (isupper(s[0]) && isupper(s[1])) {
            i = 1;
            while (++i < len)
                if (islower(s[i]))  return false ;
        } else {
            i = 0;
            while (++i < len)
                if (isupper(s[i]))  return false ;
        }
        return true ;
    }
};

*/

//  Solution 1: brute force

/*

class Solution {
public:
    bool detectCapitalUse(string s)
    {
        int len = s.length();
        if (len < 2)    return true ;
        if (s[0] < 123 && s[0] > 96){
            int i = -1;
            while (++i < len)
                if (s[i] < 97 || s[i] > 122)
                    return false ;
        }
        if (s[0] < 91 && s[0] > 64){
            if (s[1] < 91 && s[1] > 64){
                int i = 1;
                while (++i < len)
                    if (s[i] < 65 || s[i] > 90)
                        return false ;
            } else {
                int i = 1;
                while (++i < len)
                    if (s[i] < 91 && s[i] > 64)
                        return false ;
            }
        }
        return true ;
        
    }
};

*/
