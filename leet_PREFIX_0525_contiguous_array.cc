class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int(*)(vector<int>&)> Solutions {
            // Using_map,
            Using_vector,
        };
        return Solutions[0](nums);
    }

    static int Using_vector(vector<int>& nums)
    {
        int N = (int) nums.size();
        // int summing[ N * 2 + 1 ] = {};
        std::vector<int> summing(N * 2 + 1, 0);
        int res = 0;
        int curr = N;//0;
        int i = -1;
        while (++i < N) {
            if (nums[i] == 0)
                curr--;
            else
                curr++;
            if (curr == N) res = i + 1;
            else
            {
                if (summing[curr] != 0)
                    res = max(res, i - summing[curr] + 1);
                else
                    summing[curr] = i + 1;
            }
        }
        return res;
    }

    static int Using_map(vector<int>& nums)
    {
        int res = 0;
        unordered_map<int, int> D;
        D[0] = -1;
        int curr = 0;
        int N = (int) nums.size();
        int i = -1;
        while (++i < N) {
            if (nums[i])
                ++curr;
            else
                --curr;
            if (D.find(curr) == D.end())
                D[curr] = i;
            else
                res = max(res, i - D[curr]);
        }
        return res;
    }
};
