class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:

        n = random.randint(0,1)
        print([ 'Solution_3sets', 'Solution_1dict' ][ n ])
        return [ self.Solution_3sets, self.Solution_1dict ][ n ](matches)

    # Soln 1 - o(n) s(3n) ---> Using a win-set 
    # and 2 loser-sets - one for 1-lost and an extra for more-than-1 loses

    def Solution_3sets(self, matches): 
        wins, lose, lss = set(),set(),set()
        for w, l in matches:
            if l in wins:
                wins.discard(l)
                lose.add(l)
            elif l in lose:
                lose.discard(l)
                lss.add(l)
            elif l not in lss:
                lose.add(l)
            if w not in lose and w not in lss:#(lose | lss):
                # (lose|lss) is a costly operation
                wins.add(w)
        return [ sorted(wins), sorted(lose) ]

    # Solution 2 - o(n)
    # Only one dict/map will do the job

    def Solution_1dict(self, matches):
        P = defaultdict(int)
        for w, l in matches: # count loses only
            if w not in P:
                P[w] = 0
            P[l] += 1
        L, R = [], []
        for k, v in P.items():
            if v == 0: L.append(k)
            if v == 1: R.append(k)
        return [ sorted(L), sorted(R) ]
