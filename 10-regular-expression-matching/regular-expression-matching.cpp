class Solution {
private:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i>=s.size() && j>=p.size()) return true;
        if(j>=p.size()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool match = i<s.size() && (s[i]==p[j]||p[j]=='.');
        if(j+1<p.size() && p[j+1]=='*'){
            return dp[i][j]= f(i,j+2,s,p,dp) || (match && (f(i+1,j,s,p,dp)));
        }
        if(match) return dp[i][j]= f(i+1,j+1,s,p,dp);
        return dp[i][j]= false;    
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return f(0,0,s,p,dp);
    }
};