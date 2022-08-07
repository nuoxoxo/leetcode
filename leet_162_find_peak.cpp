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
    int findPeakElement(vector<int>& nums)
    {
        int L, R, mp;

        R = nums.size();

        if (R == 1 || nums[0] > nums[1])
            return 0;
        if (nums[R - 1] > nums[R - 2])
            return R - 1;

        L = 0;
        while (L < R)
        {
            mp = (L + R) / 2 ;
            cout << mp << endl;
            if (nums[mp - 1] < nums[mp] && nums[mp] > nums[mp + 1])
                return mp ;
            if (nums[mp - 1] < nums[mp])
                L = mp + 1;
            else
                R = mp;
        }
        return -1 ;
    }
};
