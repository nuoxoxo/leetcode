class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::set<int> arr;
        int res = 0;
        int i = 0;
        while (++i < k + 1)
            arr.insert(i);
        while (!arr.empty() && !nums.empty())
        {
            int n = nums.back();
            nums.pop_back();
            if (arr.count(n) > 0)
                arr.erase(n);\
            res++;
        }
        return res;
    }
};
