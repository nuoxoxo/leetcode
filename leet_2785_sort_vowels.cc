class Solution {
public:
    string sortVowels(string s)
    {
        string v = "aeiouAEIOU";
        string vo;
        for (char c: s)
        {
            if (v.find(c) != string::npos)
                vo += c;
        }
        sort(vo.begin(), vo.end());
        // cout << vo;
        string res;
        int i = 0;
        for (char c: s)
        {
            if (v.find(c) == string::npos)
                res += c;
            else
            {
                res += vo[i];
                i++;
            }
        }
        return res;
    }
};
