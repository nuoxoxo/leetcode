impl Solution {
    pub fn average_waiting_time(customers: Vec<Vec<i32>>) -> f64
    {
        let N = customers.len();
        let mut W = 0.0;
        let mut elapse = customers[0][0] as f64;
        for pair in & customers {
            let arrive = pair[0] as f64;
            let prepare = pair[1] as f64;
            if elapse < arrive {
                elapse = arrive;
            }
            W += elapse - arrive + prepare;
            elapse += prepare;
        }
        W / (N as f64)
    }
}
