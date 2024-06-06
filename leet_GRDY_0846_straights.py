class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        D = collections.Counter(hand)
        for key in sorted(D.keys()):
            while D[key] != 0:
                for r in range(groupSize):
                    if D[key + r] == 0:
                        return False
                    D[key + r] -= 1
        return True
