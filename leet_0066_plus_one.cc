class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int i = digits.size();
        while (--i > -1)
        {
            if (digits[i] ^ 9)
            {
                digits[i] += 1;
                return digits ;
            }
            else
            {
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits ;
    }
};
