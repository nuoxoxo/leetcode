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
    def findMaxLength(self, nums: List[int]) -> int:
        E = dict()
        res = 0
        count = 0
        for i in range(len(nums)):
            count = count - 1 if nums[i] == 0 else count + 1
            if count == 0:
                res = i + 1
            else:
                if count not in E:
                    E[count] = i
                else:
                    tmp = i - E[count]
                    if tmp > res:
                        res = tmp
        return res 
