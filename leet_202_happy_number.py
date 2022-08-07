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
    def isHappy(self, n: int) -> bool:
        def happyMaker(n: int) -> int:
            res = 0
            while n != 0:
                tmp = (n % 10) * (n % 10)
                res += tmp
                n //= 10
            return res
        E = set()
        while True:
            n = happyMaker(n)
            if n == 1:
                return True
            if n in E:
                return False
            E.add(n)
        return True
