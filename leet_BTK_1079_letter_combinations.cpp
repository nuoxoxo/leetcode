class Solution {
public:
    int numTilePossibilities(string tiles)
    {
        int     len = tiles.size();
        int     count = -1;

        sort(tiles.begin(), tiles.end());
        recurse(tiles, len, 0, count);
        return count;
    }

    void recurse(string tiles, int len, int index, int& count)
    {
        int     n, i;

        count++;
        i = index - 1;
        while (++i < len)
        {
            if (i ^ index && tiles[i] == tiles[index])
                continue ;
            swap(tiles[i], tiles[index]);
            recurse(tiles, len, index + 1, count);
        }
    }
};
