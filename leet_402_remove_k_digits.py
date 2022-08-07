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
    def removeKdigits(self, num: str, k: int) -> str:
        L = len(num)
        s = ""
        for i in range(L):
            while s != "" and s[-1] > num[i] and k > 0:
                s = s[:-1]
                k -= 1
            s += num[i]
        while s != "" and k > 0:
            s = s[:-1]
            k -= 1
        if s == "":
            return "0"
        i = 0
        LS = len(s)
        while i < LS and s[i] == '0':
            i += 1
        if i == LS:
            return "0"
        while i ^ 0:
            s = s[1:]
            i -= 1
        return s if s != "" else "0"
