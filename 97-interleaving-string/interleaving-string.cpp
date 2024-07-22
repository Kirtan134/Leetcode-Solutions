class Solution {
private:
    map<pair<int,int>,bool> dp;
    bool solve(string s1, string s2, string s3, int i, int j){
        if (i==s1.size() && j==s2.size()) return true;
        if (dp.find({i, j}) != dp.end()) return dp[{i, j}];
        if(i<s1.size() && s1[i]==s3[i + j] && solve(s1,s2,s3,i+1,j)) return true;
        if(j<s2.size() && s2[j]==s3[i + j] && solve(s1,s2,s3,i,j+1)) return true;
        return dp[{i, j}]=false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size()!=s1.size()+s2.size()) return false;
        return solve(s1,s2,s3,0,0);
    }
};