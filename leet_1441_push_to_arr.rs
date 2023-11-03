impl Solution {
    pub fn build_array(target: Vec<i32>, n: i32) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();
        let mut cur = 0;
        let mut i = 1;
        while cur < target.len() {
            if target[cur] == i {
                res.push("Push".to_string());
                cur += 1;
            } else {
                res.push("Push".to_string());
                res.push("Pop".to_string());
            }
            i += 1
        }
        res
    }
}
