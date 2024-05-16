class Solution {
public:
    vector<int> numberGame(vector<int>& nums)
    {
        vector<vector<int>(*)(vector<int>&)> solutions {
            // Using_priority_queue,
            Sort_and_swap,
        };
        return solutions[0](nums);
    }

    static vector<int> Sort_and_swap(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        int i = 0;
        while (i < nums.size())
        {
            swap(nums[i], nums[i + 1]);
            i += 2;
        }
        return nums;
    }

    static vector<int> Using_priority_queue(vector<int>& nums)
    {
        std::priority_queue<int, vector<int>, std::greater<int>> Q(begin(nums), end(nums));
        vector<int> res;
        while (!Q.empty())
        {
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            res.push_back(b);
            res.push_back(a);
        }
        return res;
    }
};
