# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}

def combination_sum4(nums, target)
    dp = [1] + [0] * target
    (1..target).each do |i|
        nums.each do |n|
            dp[i] += dp[i - n] if i >= n
        end
    end
    dp.last
end

=begin
def combination_sum4(nums, target)
    dp = [1] + Array.new(target, 0)
    for i in 1..target
        for n in nums
            dp[i] += dp[i - n] if i >= n
        end
    end
    dp[target]
end
=end
