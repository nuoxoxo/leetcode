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
    def intervalIntersection(self, first: List[List[int]], second: List[List[int]]) -> List[List[int]]:
        res = []
        i = 0
        j = 0
        while i < len(first) and j < len(second):
            lo = max(first[i][0], second[j][0])
            hi = min(first[i][1], second[j][1])
            if lo <= hi:    res.append( [lo, hi] )
            if first[i][1] < second[j][1]:
                i += 1
            else:
                j += 1
        return res
                
