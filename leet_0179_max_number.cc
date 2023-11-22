class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string>  S;
        for (int n: nums)
            S.push_back(to_string(n));
        sort(S.begin(), S.end(), [](string a, string b){
            return a + b > b + a;
        });
        string res;
        for (string s: S)
            res += s;
        int i = 0;
        while (res[i] == '0')
            ++i;
        res.erase(0, i);
        if (res == "")
            return "0"; 
        return res;
    }
};
