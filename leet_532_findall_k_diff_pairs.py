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
    def findPairs(self, nums: List[int], k: int) -> int:
        c = 0
        i = 0
        j = 1
        nums.sort()
        s = len(nums)
        while i < s and j < s:
            o = nums[j] - nums[i]
            if o == k and i != j:
                c += 1
                while i + 1 < s and nums[i + 1] == nums[i]:
                    i += 1
                while j + 1 < s and nums[j + 1] == nums[j]:
                    j += 1
                i += 1
                j += 1
            elif o < k:
                j += 1
            else:
                i += 1
        return c
