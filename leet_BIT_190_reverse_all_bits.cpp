
class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        std::string s = std::bitset<32>(n).to_string();
        std::string r = std::string(s.rbegin(), s.rend());

        return stoul(r, nullptr, 2);
    }
};
