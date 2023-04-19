class Solution {
public:
    int findComplement(int num) {
        string  mid;
        while (num)
        {
            mid = to_string(num % 2 ^ 1) + mid;
            num /= 2;
        }
        // cout << mid << endl;
        return stoi(mid, 0, 2);
    }
};
