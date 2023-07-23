class Solution:
    def asteroidCollision(self, ads: List[int]) -> List[int]:
        Q = []
        i = 0
        while i < len(ads):
            if not Q:
                Q.append(ads[i])
                i += 1

            # ( -, + ) <queue[-1], incoming>
            # ---> No collision bc they part ways ( << , >> )
            elif ads[i] > -1:
                # this one moves >> or stays put
                Q.append(ads[i])
                i += 1
            elif Q[-1] < 0:
                # this one moves <<
                Q.append(ads[i])
                i += 1

            # ( + , - )<queue[-1], incoming>
            # ---> Is the only possoble colliding scenario
            elif Q[-1] + ads[i] == 0:
                # either they cancel each other
                Q.pop()
                i += 1
            elif Q[-1] + ads[i] < 0:
                # or queue[-1] gets eaten
                Q.pop()
            else:
                i += 1
        return Q
