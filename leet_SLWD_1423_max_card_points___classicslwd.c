

int maxScore(int* p, int pSize, int k)
{
    int best = 0;
    int i = -1;
    while (++i < k)
        best += p[i];
    int temp = best;
    i = 0;
    while (++i < k + 1)
    {
        temp += p[pSize - i];
        temp -= p[k - i];
        best = best > temp ? best : temp;
    }
    return best;
}
