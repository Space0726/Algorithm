impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut max_val = 0;
        for i in 1..prices.len() {
            if prices[i] > prices[i-1] {
                max_val += prices[i] - prices[i-1];
            }
        }
        max_val
    }
}
