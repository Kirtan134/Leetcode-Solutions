class Solution {
private:
    int f(int idx,vector<int>& arr, int k, vector<int>& dp){
        int n = arr.size();
        if(idx==n) return 0;
        int maxi=INT_MIN, maxAns=INT_MIN, len=0;
        for(int i=idx;i<min(idx+k,n);i++){
            len++;
            maxi=max(maxi,arr[i]);
            int sum = len*maxi+f(i+1,arr,k,dp);
            maxAns=max(maxAns,sum);
        }
        return dp[idx]=maxAns;
    }
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