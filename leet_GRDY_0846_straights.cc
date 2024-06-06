class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {

        // greedy

        int N = hand.size();
        if (N < groupSize || N % groupSize)
            return false;
        // sorted and mapped, then we have sorted keys
        sort(begin(hand), end(hand));
        map<int, int> D;
        for (int n : hand)
            D[n]++;
        // to set -> to vec again, for looping through sorted keys
        auto it = std::unique(begin(hand), end(hand));
        hand.erase(it, hand.end());
        N = hand.size();
        int i = -1;
        while (++i < N)
        {
            int key = hand[i];
            while (D[key])
            {
                int R = -1; 
                while (++R < groupSize)
                {
                    if (D[key + R] == 0)
                        return false;
                    D[key + R]--;
                }
            }
        }
        return true;
    }
};
