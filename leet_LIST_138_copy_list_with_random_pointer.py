class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        E = defaultdict(lambda: None) """E = {None: None}""" 
        curr = head
        while curr:
            temp = Node(curr.val)
            E[curr] = temp
            curr = curr.next
        curr = head
        while curr:
            temp = E[curr]
            temp.next = E[curr.next]
            temp.random = E[curr.random]
            curr = curr.next
        return E[head]
