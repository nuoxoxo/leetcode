impl Solution {
    pub fn get_winner(arr: Vec<i32>, k: i32) -> i32 {
        let hi = *arr.iter().max().unwrap();
        let len = arr.len();
        if len <= k as usize {
            return hi;
        }
        let mut res = arr[0];
        let mut count = 0;
        let mut i = 1;
        while i < len {
            if res < arr[i] {
                count = 1;
                res = arr[i];
            } else {
                count += 1;
            }
            if count == k as usize {
                return res;
            }
            i += 1
        }
        hi
    }
}
