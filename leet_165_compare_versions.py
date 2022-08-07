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
    def compareVersion(self, version1: str, version2: str) -> int:
        n1=len(version1)
        n2=len(version2)
        o = ord('0')
        r1=r2=i=j=0
        while i < n1 or j < n2:
            while i < n1 and version1[i] is not '.':
                r1 = r1 * 10 + ord(version1[i]) - o
                i += 1
            while j < n2 and version2[j] is not '.':
                r2 = r2 * 10 + ord(version2[j]) - o
                j += 1
            if r1 < r2: return -1
            if r1 > r2: return 1
            r1 = r2 = 0
            i += 1
            j += 1
        return 0
