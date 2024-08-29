class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j] && dp[i] < 1 + dp[j]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (nums[i] > nums[j] && dp[i] == 1 + dp[j]) {
                    cnt[i] += cnt[j];
                }
                maxi = max(maxi, dp[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};