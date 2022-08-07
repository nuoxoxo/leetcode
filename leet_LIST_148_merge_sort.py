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
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        L = head
        mp = self.findMidpoint(head)
        R = mp.next
        mp.next = None;
        L = self.sortList(L)
        R = self.sortList(R)
        return self.mergeSort(L, R)

    def mergeSort(self, p: ListNode, q: ListNode) -> ListNode:
        if p is None and q is None: return None
        if p and q is None: return p
        if p is None and q: return q
        L = None
        R = None
        x = p
        y = q
        if x.val < y.val:
            L = R = x
            x = x.next
        else:
            L = R = y
            y = y.next
        while x and y:
            if x.val < y.val:
                R.next = x
                x = x.next
                R = R.next
            else:
                R.next = y
                y = y.next
                R = R.next
        while x:
            R.next = x
            x = x.next
            R = R.next
        while y:
            R.next = y
            y = y.next
            R = R.next
        R.next = None
        return L
        
    def findMidpoint(self, p: ListNode) -> ListNode:
        if p is None or p.next is None:
            return p
        rab = p.next
        tur = p
        while rab and rab.next:
            rab = rab.next.next
            tur = tur.next
        return tur
