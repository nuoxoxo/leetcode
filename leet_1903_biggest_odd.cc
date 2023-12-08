class Solution {
public:
    string largestOddNumber(string num) {
        while (num != "") {
            if ((num[num.length() - 1] - '0') % 2)
                break ;
            num.pop_back();
        }
        return num;
    }
};
