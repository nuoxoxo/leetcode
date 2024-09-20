# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        return [
            modulo_trick
        ][0](m, n, head)

def modulo_trick(m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        res = [[-1] * n for _ in range(m)]
        D = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        idx = 0
        r, c = 0, 0
        node = head
        while node:
            res[r][c] = node.val
            dr, dc = D[idx]
            rr, cc = r + dr, c + dc
            if not -1 < rr < m or not -1 < cc < n or res[rr][cc] != -1:
                idx = (idx + 1) % 4
            dr, dc = D[idx]
            rr, cc = r + dr, c + dc
            r, c = rr, cc
            node = node.next
        return res
