#* ******************************************** *#
#*                                              *#
#*              \\             /`/``            *#
#*              ~\o o_       0 0\               *#
#*              / \__)      (u  ); _  _         *#
#*       / \/ \/  /           \  \/ \/ \        *#
#*      /(   . . )            (         )\      *#
#*     /  \_____/              \_______/  \     *#
#*         []  []               [[] [[]    *.   *#
#*         []] []]              [[] [[]         *#
#*                                              *#
#* ************************************ nuo *** *#

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        if len(nums) is 1:
            return nums[0]
        nums.sort()
        if nums[0] != nums[1]:
            return nums[0]
        i = 0
        while i < len(nums) - 2:
            if nums[i] == nums[i + 1]:
                i += 2
            else:
                break ;
        return nums[i]
