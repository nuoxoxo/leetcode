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
    void moveZeroes(vector<int>& nums) {
        int     size, i, j;

        i = -1;
        size = (int) nums.size();
        while (++i < size)
        {
            if (!nums[i])
            {
                j = i;
                while (j < size && !nums[j])
                    ++ j ;
                if (j == size)
                    return ;
                nums.erase(nums.begin() + i);
                nums.push_back(0);
		--i ;
            }
        }
    }
};
