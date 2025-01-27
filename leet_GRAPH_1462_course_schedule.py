class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        # floyd warshall algo
        dp = [[False] * numCourses for _ in range(numCourses)]
        for u,v in prerequisites:
            dp[u][v] = True
        for k in range(numCourses): # standard Floyd-Warshall implementation
            for i in range(numCourses):
                for j in range(numCourses):
                    dp[i][j] |= dp[i][k] and dp[k][j]
        return [dp[u][v] for u,v in queries]

        
