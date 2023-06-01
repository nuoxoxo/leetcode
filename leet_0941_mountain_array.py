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
    def validMountainArray(self, a: List[int]) -> bool:
        if len(a) < 3:
            return False
        asc = False
        des = False
        i = 1
        while i < len(a) and a[i] > a[i - 1]:
            asc = True
            i += 1
        while i < len(a) and a[i] < a[i - 1]:
            des = True
            i += 1
        if i == len(a) and asc and des:
            return True
        return False
