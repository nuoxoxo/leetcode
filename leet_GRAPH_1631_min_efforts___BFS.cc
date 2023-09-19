class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int C = heights[0].size();
        int R = heights.size();
        vector<vector<int>> dirs = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> dq;
        dq.push(vector<int>{0, 0, 0});

        unordered_set<int> seen;
        
        while (!dq.empty())
        {
            vector<int> top = dq.top();
            dq.pop();
            int eff = top[0];
            int r = top[1];
            int c = top[2];            
            if (seen.find(r * C + c) != seen.end())
                continue;
            seen.insert(r * C + c);
            
            if (r == R - 1 && c == C - 1)
                return eff;

            for (vector<int> & dir : dirs)
            {
                int dr = dir[0];
                int dc = dir[1];
                int rr = r + dr;
                int cc = c + dc;
                
                if (rr < 0 || rr == R || cc < 0 || cc == C 
                    || seen.find(rr * C + cc) != seen.end())
                    continue;
                
                int temp = max(eff, abs(heights[r][c] - heights[rr][cc]));
                dq.push(vector<int>{temp, rr, cc});
            }
        }
        return 0;
    }
};
