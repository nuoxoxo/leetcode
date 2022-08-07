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
    double average(vector<int>& s)
    {
        double  mx = *std::max_element(s.begin(), s.end());
        double  mn = *std::min_element(s.begin(), s.end());
        return (accumulate(s.begin(), s.end(), 0) - mx - mn) / ((int) s.size() - 2);
    }
};
