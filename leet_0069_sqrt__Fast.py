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
    def mySqrt(self, x: int) -> int:
        mp = x // 2
        L = 0
        R = x
        res = 0
        while L <= R:
            tmp = mp * mp
            if tmp == x:
                return mp
            elif tmp > x:
                R = mp - 1
            else:
                res = mp
                L = mp + 1
            mp = (R - L) // 2 + L
        return res
