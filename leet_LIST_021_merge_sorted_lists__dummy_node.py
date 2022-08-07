#* ************************************************************************** *#
#*                                                                            *#
#*                            \\             #`#``                            *#
#*                            ~\o o_       0 0\                               *#
#*                            # \__)      (u  ); _  _                         *#
#*                     # \# \#  #           \  \# \# \                        *#
#*                    #(   . . )            (         )\                      *#
#*                   #  \_____#              \_______#  \                     *#
#*                       []  []               [[] [[]    *.                   *#
#*                       []] []]              [[] [[]                         *#
#*                                                                            *#
#* ****************************************************************** .py *** *#

class Solution:
    def mergeTwoLists(self, L1: Optional[ListNode], L2: Optional[ListNode]) -> Optional[ListNode]:
        if L1 is None:
            return L2
        if L2 is None:
            return L1
        dumm = ListNode(0)
        head = dumm;
        while L1 is not None and L2 is not None:
            if L1.val < L2.val:
                head.next = L1
                L1 = L1.next
            else:
                head.next = L2
                L2 = L2.next
            head = head.next
        head.next = L1 if L1 is not None else L2
        return dumm.next
