class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        return [
            # Minheapq_and_namedtuple,
            Minheapq_only,
        ][0](k, w, profits, capital)

def Minheapq_only(k: int, w: int, profits: List[int], capital: List[int]) -> int:
    CP = sorted(zip(capital, profits), key=lambda x : x[0])
    i = 0
    res = w # wealth
    Q = []
    for _ in range(k):
        while i < len(profits) and CP[i][0] <= res:
            # print(i, len(profits))
            p = -CP[i][1]
            heapq.heappush(Q, -CP[i][1])
            i += 1
        if not Q:
            return res
        res += -heapq.heappop(Q)
    return res

# OT( N * logN + K * logN )
def Minheapq_and_namedtuple(k: int, w: int, profits: List[int], capital: List[int]) -> int:
    assert len(profits) == len(capital)
    CP = []
    cptuple = collections.namedtuple('cptuple', ['cap', 'prof'])
    for c, p in zip(capital, profits):
        CP.append(cptuple(c, p))
    CP.sort()
    Q = []
    heapq.heapify(Q)
    N = len(profits)
    res = w
    i = 0
    for _ in range(k):
        while i < N and CP[i].cap <= res:
            heapq.heappush(Q, -CP[i].prof) # minheap
            i += 1
        if not Q:
            return res
        res += -heapq.heappop(Q) # minheap
    return res
