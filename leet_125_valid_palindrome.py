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
    def isPalindrome(self, s: str) -> bool:
        zero = ord('0')
        nine = ord('9')
        A = ord('A')
        a = ord('a')
        Z = ord('Z')
        z = ord('z')
        ss = ""
        for c in s:
            o = ord(c)
            if A <= o <= Z:
                ss += chr(o + 32)
            if a <= o <= z or zero <= o <= nine:
                ss += c
        return self.P(ss)
            
    def P(self, s: str) -> bool:
        L = len(s)
        for i in range(L // 2):
            if s[i] is not s[L - 1 - i]:
                return False
        return True
