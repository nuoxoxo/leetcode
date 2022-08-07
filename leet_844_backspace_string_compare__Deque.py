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
    def backspaceCompare(self, s: str, t: str) -> bool:
        ss = deque()
        tt = deque()
        ls = len(s)
        lt = len(t)
        for i in range(ls):
            if s[i] != '#':
                ss.append(s[i])
            elif ss:
                ss.pop()
        for i in range(lt):
            if t[i] != '#':
                tt.append(t[i])
            elif tt:
                tt.pop()
        return tt == ss
