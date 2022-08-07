class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        int n = letters.size();
        int L = 0;
        int R = n;
        while (L < R)
        {
            int mp = (R - L) / 2 + L;
            if (letters[mp] <= target)
                L = mp + 1;
            else
                R = mp;
        }
        if (R == n)
            return letters[0];
        return letters[R];
    }
};
