class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        vector<int(*)(vector<int>&)> Solutions {
            // direct_solution,
            using_counter,
        };
        return Solutions[0](nums);
    }

    static int direct_solution(vector<int>& nums) {
        set<int> S(nums.begin(), nums.end());
        int UN = S.size();
        int N = nums.size();
        int res = 0, L = -1, R;
        while (++L < N)
        {
            set<int> SS;
            R = L - 1;
            while (++R < N)
            {
                SS.insert(nums[R]);
                if (SS.size() == UN)
                    res++;
            }
        }
        return res;
    }

    static int using_counter(vector<int>& nums) {
        set<int> S(nums.begin(), nums.end());
        int UN = S.size(), N = nums.size();
        int res = 0, L = -1, R = 0;
        unordered_map<int,int> D;
        while (++L < N)
        {
            D[nums[L]]++;
            while (D.size() == UN)
            {
                D[nums[R]]--;
                if ( !D[nums[R]])
                    D.erase(nums[R]);
                res += N - L;
                // we count every subarr that has:
                //      L as left-bound
                //      R:N+1 as right-bound
                ++R;
            }
        }
        return res;
    }

};
