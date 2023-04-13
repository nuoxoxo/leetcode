impl Solution {
    pub fn validate_stack_sequences(pushed: Vec<i32>, popped: Vec<i32>) -> bool {
        let mut a: Vec<i32> = vec![];
        // let mut idx: usize = 0;
        let mut idx = 0;
        // for n in pushed {
        for & n in & pushed {
            a.push(n);
            while a.len() != 0 && a[a.len() - 1] == popped[idx] {
                a.pop();
                idx += 1;
            }
        }
        return a.len() == 0;
    }
}
