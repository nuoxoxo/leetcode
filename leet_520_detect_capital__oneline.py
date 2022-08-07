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

"""
class Solution:
    def detectCapitalUse(self, s: str) -> bool:
        return s.islower() or s.isupper() or s.istitle()
"""

class Solution:
    def detectCapitalUse(self, s: str) -> bool:
        return len(s) < 2 or max(s) <= 'Z' or min(s[1:]) >= 'a'
