class Solution:
    # def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
    def survivedRobotsHealths(self, P: List[int], H: List[int], D: str) -> List[int]:
        pos = {}
        for i, p in enumerate(P):
            pos[p] = i
        pos = dict(sorted(pos.items()))
        Q = []
        for robot, idx in pos.items():
            if D[idx] == 'R':
                Q.append(robot)
            elif D[idx] == 'L':
                while Q and D[pos[Q[-1]]] == 'R':
                    RmovingRobot = Q.pop()
                    RmovingIndex = pos[ RmovingRobot ]
                    RH = H[ RmovingIndex ]
                    currH = H[idx]
                    if RH < currH:
                        RH = 0
                        currH -= 1
                    elif RH > currH:
                        RH -= 1
                        Q.append( RmovingRobot )
                        currH = 0
                    else:
                        RH = 0
                        currH = 0
                    H[ RmovingIndex ] = RH
                    H[idx] = currH
                    if currH < 1:
                        break
                if H[idx] > 0:
                    Q.append(robot)
            # print(H)
        return [h for h in H if h > 0]
