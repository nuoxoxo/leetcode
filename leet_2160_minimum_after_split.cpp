class Solution {
public:
    int minimumSum(int num)
    {
        vector<int> t;

        while (num)
        {
            t.push_back(num % 10);
            num /= 10;
        }
        sort(t.begin(), t.end());
        return (t[0] + t[1]) * 10 + t[2] + t[3];
    }
};
