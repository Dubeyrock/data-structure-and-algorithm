public class Solution {
    public long CountGood(int[] nums, int k) {
        int n = nums.Length;
        int same = 0, right = -1;
        Dictionary<int, int> cnt = new Dictionary<int, int>();
        long ans = 0;
        for (int left = 0; left < n; ++left) {
            while (same < k && right + 1 < n) {
                ++right;
                cnt.TryGetValue(nums[right], out int current);
                same += current;
                cnt[nums[right]] = current + 1;
            }
            if (same >= k) {
                ans += n - right;
            }
            cnt[nums[left]] = cnt[nums[left]] - 1;
            same -= cnt[nums[left]];
        }
        return ans;
    }
}
