impl Solution {
    pub fn distribute_candies(candies: i32, num_people: i32) -> Vec<i32> {
        let mut res = vec![0; num_people];
        let mut idx = 0;
        let mut c = 0;
        let mut n;
        while candies > 0 {
            c += 1;
            n = std::cmp::min(candies, c);
            candies -= n;
            res[idx] += n;
            idx = (idx + 1) % num_people;
        }
        res
    }
}
