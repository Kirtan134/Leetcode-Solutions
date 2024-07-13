class Solution {
private:
    int f(int idx,vector<int>& arr, int k, vector<int>& dp){
        int n = arr.size();
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
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
        vector<int> dp(n,-1);
        return f(0,arr,k,dp);
    }
};