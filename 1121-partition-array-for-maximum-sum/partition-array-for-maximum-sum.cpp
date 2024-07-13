class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            int maxi=INT_MIN, maxAns=INT_MIN, len=0;
            for(int i=idx;i<min(idx+k,n);i++){
                len++;
                maxi=max(maxi,arr[i]);
                int sum = len*maxi+dp[i+1];
                maxAns=max(maxAns,sum);
            }
            dp[idx]=maxAns;
        }
        return dp[0];
    }
};