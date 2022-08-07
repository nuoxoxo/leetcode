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
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0:
            return None
        arr = []
        for node in lists:
            while node:
                arr.append(node.val)
                node = node.next
        if len(arr) == 0:
            return None
        arr.sort()
        res = ListNode()
        tmp = res
        for n in arr:
            p = ListNode()
            p.val = n
            tmp.next = p
            tmp = tmp.next
        return res.next
