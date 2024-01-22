class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        vector< vector<int>(*)(vector<int>&) > Solutions {
            Solution_DP,
            Solution_Sorting_1pass,
        };
        return Solutions[ std::rand() % Solutions.size() ](nums);
    }

    static vector<int> Solution_Sorting_1pass (vector<int> & nums) 
    {
        cout << "/Solution_Sorting_1pass\n";
        sort(nums.begin(), nums.end());
        int len = (int) nums.size();
        vector<int> res = {0,0};
        res [1] = nums[len - 1] == len ? 1 : len;
        
        int i = 0;
        while (++i < len)
        {
            if (nums[i] == nums[i - 1])
                res[0] = nums[i - 1];
            else if (nums[i] > nums[i - 1] + 1)
                res[1] = nums[i - 1] + 1;
        }
        return res;
    }

    static vector<int> Solution_DP (vector<int> & nums)
    {
        cout << "/Solution_DP\n";
        int len = (int) nums.size();
        vector<int> DP(len, 0);
        vector<int> res = {0, 0};
        for (int n: nums)
            ++DP[n - 1];
        int i = -1;
        while (++i < len)
        {
            if (DP[i] == 2)
                res[0] = i + 1;
            else if (!DP[i])
                res[1] = i + 1;
        }
        return res;
    }
};
