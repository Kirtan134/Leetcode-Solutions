#define ll long long 
class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& matrix, int n, int m, vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int maxLength=1;
        if(i+1<n && matrix[i+1][j]>matrix[i][j]) maxLength = max(maxLength,1+solve(i+1,j,matrix,n,m,dp));
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]) maxLength = max(maxLength,1+solve(i-1,j,matrix,n,m,dp));
        if(j+1<m && matrix[i][j+1]>matrix[i][j]) maxLength = max(maxLength,1+solve(i,j+1,matrix,n,m,dp));
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]) maxLength = max(maxLength,1+solve(i,j-1,matrix,n,m,dp));
        return dp[i][j]=maxLength;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result=max(result,solve(i,j,matrix,n,m,dp));
            }
        }
        return result;
    }
};