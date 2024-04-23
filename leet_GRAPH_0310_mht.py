class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]

        # Basic idea
        #   - finds the leaves of the tree iteratively,
        #   - until only the centroids remain ie. roots of the MHTs

        res = [] # leaves / initial leaves
        ADJ = defaultdict(list)
        for u, v in edges:
            ADJ[u].append(v)
            ADJ[v].append(u)
        degrees = [None] * n
        for i in range(n):
            degrees[i] = len(ADJ[i])

            # initial leaves
            #   - nodes with only one edge
            if degrees[i] == 1:
                res.append(i)
                degrees[i] -= 1
        print('res - init/', res)
        print('deg - init/', degrees)
        while True:
            # remove leaves until only the centroids ie. roots of MHTs remain
            #   - it is Greedy
            #   - reduce the tree's dimension in each iteration by removing leaves
            #   - once there are no new leaves, all there remains are centroids
            new_leaves = []
            for u in res:
                for v in ADJ[u]:
                    if degrees[v] > 0:
                        degrees[v] -= 1
                        if degrees[v] == 1:
                            new_leaves.append(v)
            if not new_leaves:
                break
            print('res/', new_leaves)
            print('deg/', degrees)
            res = new_leaves
        return res

