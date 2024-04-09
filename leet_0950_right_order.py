class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        N = len(deck)
        dq = deque(range(N))
        res = [None] * N
        for n in deck:
            idx = dq.popleft()
            res[ idx ] = n
            if dq:
                dq.append(dq.popleft())
        return res
