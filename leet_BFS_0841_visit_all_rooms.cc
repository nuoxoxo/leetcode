class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<bool> seen(rooms.size(), false);
        deque<int> dq = {0};
        // BFS
        while (!dq.empty())
        {
            int len = (int) dq.size();
            int i = -1;
            int room;
            while (++i < len)
            {
                room = dq.front();
                dq.pop_front();
                seen[room] = true;
                for (int r: rooms[room])
                {
                    if (!seen[r])
                        dq.push_back(r);
                }
            }
        }
        int bfs = count(seen.begin(), seen.end(), true);
        return bfs == (int) rooms.size();
    }
};
