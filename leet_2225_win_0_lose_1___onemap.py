class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        players = {}
        for m in matches:
            a, b = m[0], m[1]
            if a not in players:
                players[a] = 0
            if b not in players:
                players[b] = 1
            else:
                players[b] += 1
        winall = []
        lose1 = []
        # print(players)
        for key, value in players.items():
            if value == 0:
                winall.append(key)
            if value == 1:
                lose1.append(key)
        return [ sorted(winall), sorted(lose1) ]
        
