class Solution {
    public int[] searchRange(int[] nums, int target) {
        List<Integer>   n = Arrays.stream(nums).boxed().collect(Collectors.toList());
        int             left = n.indexOf(target);
        int             right = n.lastIndexOf(target);
        int[]           res = new int[2];

        res[0] = left;
        res[1] = right;
        // System.out.println(left + " " + right); /* (left + ' ' + right) won't work */
        return res;
    }
}
