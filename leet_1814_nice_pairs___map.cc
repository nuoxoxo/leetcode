class Solution {
public:
    int countNicePairs(vector<int>& nums)
    {
        // Logic
        //nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
        //nums[i] - rev(nums[i]) == nums[j] - rev(nums[j]) 

        unordered_map<int, long long>   D;
        int MOD = int(1e9) + 7;
        for (int n: nums)
        {
            int rev = 0;
            int rem = 0;
            int original = n;
            while (n)
            {
                rev *= 10;
                rev += n % 10;
                n /= 10;
            }
            // cout << rev << endl;
            D[(original - rev)]++;
        }
        int res = 0;
        for (pair<int, long long> p: D)
        {
            // BUG :
            // res += p.second * (p.second - 1) / 2 % MOD;
            // bug bc. in c++ modulo % has higher precedence than += 
            res = (res + p.second * (p.second - 1) / 2) % MOD;
        }
        return res;
    }
};
