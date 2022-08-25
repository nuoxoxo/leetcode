class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int>     mp(26, 0);

        for (char c : magazine)
            mp[c - 'a']++;
        for (char c : ransomNote)
        {
            mp[c - 'a']--;
            if (mp[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
