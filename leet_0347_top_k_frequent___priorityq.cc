class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        priority_queue<pair<int, int>>  q;
        unordered_map<int, int>         m;
        vector<int>                     res;

        for (int n: nums)
            m[n] += 1;
        for (pair<int, int> p: m)
            q.push(make_pair(p.second, p.first));
        while (k)
        {
            res.push_back(q.top().second);
            q.pop();
            k -= 1;
        }
        return res;
    }
};
