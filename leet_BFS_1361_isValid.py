class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        if n == 1:
            # True if having only 2 children AND no grandchildren
            return len(leftChild) == 1 and leftChild[0] == -1 \
                and len(rightChild) == 1 and rightChild[0] == -1
        R = []
        Lset = set(leftChild)
        Rset = set(rightChild)
        for node in range(n):
            if node not in Lset and node not in Rset \
                and (leftChild[node] > -1 or rightChild[node] > -1):
                R.append(node)
        if len(R) != 1:
            return False
        root = R[0]
        dq = [root]
        seen = set()
        while dq:
            size = len(dq)
            for i in range(size):
                node = dq.pop(0)
                if node == -1:
                    continue
                if node in seen:
                    return False
                seen.add(node)
                dq.append(leftChild[node])
                dq.append(rightChild[node])
        return len(seen) == n


