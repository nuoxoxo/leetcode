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
    int maxSubArray(vector<int>& nums)
    {
        int res = nums[0];
        int i = 0;
        while (++ i < nums.size())
        {
            nums[i] = max(nums[i], nums[i] + nums[i - 1]);
            res = max(res, nums[i]);
        }
        return res ;
    }
};
