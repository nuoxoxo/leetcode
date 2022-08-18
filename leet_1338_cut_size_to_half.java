class Solution {
    public int minSetSize(int[] arr)
    {
        var mp = new HashMap<Integer, Integer>();
        int count, res, la;
        for (int n : arr)
            mp.put(n, mp.getOrDefault(n, 0) + 1);
        var arr2 = new ArrayList<Integer>(mp.values());
        Collections.sort(arr2);
        Collections.reverse(arr2);
        System.out.println(arr2);
        la = arr.length;
        count = la;
        res = 0;
        for (Integer n : arr2)
        {
            if (count <= la / 2)
                return res;
            count -= n;
            res += 1;
        }
        return res;
    }
}

/*
problematic input:
[2,28,92,30,100,52,28,48,91,27,66,19,11,53,91,95,74,51,65,65,96,81,21,55,98,3,2,89,99,57,78,34,50,2,57,76,23,90,89,36,53,22,73,59,95,45]
*/

/*  (to ignore:)
[4, 2, 3, 1]
[6]
[1, 1]
[3, 2, 2, 2, 2, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
*/
