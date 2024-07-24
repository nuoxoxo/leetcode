class Solution {
public:
    vector<int> frequencySort(vector<int>& nums)
    {
        vector<vector<int>(*)(vector<int>&)> solutions = {
            // max_heap,
            new_dp_soln,
        };
        return solutions[0](nums);
    }

    static vector<int> new_dp_soln(vector<int>& nums)
    {
        vector<int> counter(201, 0);
        for (int n : nums)
            counter[n + 100]++;
        sort(begin(nums), end(nums), [&](int l, int r){
            if (counter[l + 100] == counter[r + 100])
                return l > r;
            return counter[l + 100] < counter[r + 100];
        });
        return nums;
    }

    static vector<int> max_heap(vector<int>& nums)
    {
        priority_queue<pair<int, int>> Q;
        unordered_map<int, int> D;
        vector<int> res(nums.size(), 0);
        for (int n : nums)
            D[n]++;
        for (auto & p : D)
            Q.push({ -p.second, p.first });
        int idx = 0;
        while (!Q.empty())
        {
            int i = -1;
            auto p = Q.top();
            while (++i < -(p.first))
                res[idx++] = p.second;
            Q.pop();
        }
        return res;
    }
};
