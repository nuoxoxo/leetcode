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
    int findPairs(vector<int>& nums, int k)
    {
        int L, i, j, count;

        sort(nums.begin(), nums.end());
        L = nums.size();
        i = count = 0;
        j = 1;
        while (i < L && j < L)
        {
            int tmp = nums[j] - nums[i];

            if (k == tmp && i != j)
            {
                count++;
                while (i + 1 < L && nums[i + 1] == nums[i]) i++;
                while (j + 1 < L && nums[j + 1] == nums[j]) j++;
                i += 1;
                j += 1;
            }
            else if (tmp < k)   j++;
            else                i++;
        }
        return count ;        
    }
};
