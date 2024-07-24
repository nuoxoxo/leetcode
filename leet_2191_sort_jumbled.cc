class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums)
    {
        // [8,9,4,0,2,1,3,5,7,6]
        //  0 1 2 3 4 5 6 7 8 9 (index)
        // [991,338,38]
        function<int(int)> go = [&](int n)
        {
            if (!n)
                return mapping[0];
            int res = 0;
            int ten = 1;
            while (n)
            {
                res += mapping[n % 10] * ten;
                ten *= 10;
                n /= 10;
            }
            return res;
        };
        sort(begin(nums), end(nums), [&](const int l, const int r){
            return go(l) < go(r);
        });
        return nums;
    }
};
