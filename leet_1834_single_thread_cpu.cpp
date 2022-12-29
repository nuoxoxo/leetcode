class Solution {
public:
    #define pll pair<long long, long long>
    vector<int> getOrder(vector<vector<int>>& tasks)
    {
        priority_queue<pll, vector<pll>, greater<>> P; // min heap
        vector<int> res;
        long long time = 0;
        int len = tasks.size();
        int i;
        i = -1;
        while (++i < len)
            tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        i = 0;
        while (i < len || P.size())
        {
            if (P.empty())
            {
                time = max((long long) tasks[i][0], time);
            }
            while (i < len && time >= tasks[i][0])
            {
                P.emplace(tasks[i][1], tasks[i][2]);
                ++i;
            }
            pll p = P.top();
            P.pop();
            time += p.first; // process
            res.push_back(p.second); // index
        }
        return res;

    }
};
