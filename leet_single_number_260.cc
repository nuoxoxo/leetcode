/*
[1,2,1,3,2,5]
[0,1,2,2]
[0,1,1,2]
[0,0,1,2]
[-1,0]
[0,1]
*/

class Solution {
public:
    #define vi vector<int>
    vector<int> singleNumber(vector<int>& nums)
    {
        vector<vi(*)(vector<int> &)> Solutions {
            // Using_set,
            // Sort_first,
            Bitwise,
        };
        return Solutions[0](nums);
    }

    static vi Bitwise( vi & nums)
    {
        long long XOR;
        for (int n: nums)
            XOR ^= n;

        // isolate the least significant set bit
        //  step 1/2 - clear the least significant set bit
        //      eg. XOR is 1100
        //      XOR - 1 is 1011
        //      XOR ^ XOR-1 = 1000 -> unset the R-most set bit
        int tmp = XOR & (XOR - 1);

        //  step 2/2 - xor itself, we have only the R-most set bit left
        XOR ^= tmp;

        int L = 0, R = 0;
        for (int n: nums)
        {
            if (XOR & n)
                L ^= n;
            else
                R ^= n;
        }
        return { L, R };
    }

    static vi Sort_first( vi & nums)
    {
        vi res;
        sort(begin(nums), end(nums));
        int N = (int) nums.size();
        int i = 0;
        if (nums[i] != nums[i + 1])
            res.push_back(nums[i]);
        if (nums.back() != nums[N - 2])
            res.push_back(nums.back());
        if (res.size() == 2)
            return res;
        while (++i < N - 1)
        {
            if (res.size() == 2)
                return res;
            if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1])
                res.push_back(nums[i]);
        }
        return res;
    }

    static vi Using_set( vi & nums)
    {
        set<int> S;
        for (int n: nums)
        {
            if (S.find(n) == end(S))
                S.insert(n);
            else
                S.erase(n);
        }
        vi res(2, 0);
        int i = 0;
        auto it = begin(S);
        while (it != end(S))
            res[i++] = *(it++);
        return res;

    }
};
