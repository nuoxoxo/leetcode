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
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        int             n = nums.size() ;
        vector<bool>    seen(n + 1, false);
        vector<int>     res;
        int             i;

        i = -1;
        while (++ i < n)
            seen[nums[i]] = true;
        i = 0;
        while (++i < seen.size())
            if (!seen[i])
                res.push_back(i);
        return (res);
    }
};
