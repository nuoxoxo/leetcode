class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        int boat = 0, lo = 0, hi = people.size() - 1;

        sort(people.begin(), people.end()) ;
        while (lo <= hi)
        {
            if (people[lo] + people[hi] <= limit)
            {
                ++lo ;
            }
            --hi ;
            ++boat; 
        }
        return (boat) ;
    }
};
