class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        int n = num.length();
        if(n==k) return "0";
        for(int i=0;i<n;i++){
            while(!ans.empty() && k>0 && ans.back()>num[i]){
                ans.pop_back(); 
                k--;
            }
            if(ans.size()>0 || num[i]!='0'){
                ans.push_back(num[i]);
            }
        } 
        //If some k is left, then remove last k elements which wil be larger.
        while(ans.size()>0 && k>0){
            ans.pop_back(); 
            k--;
        }
        return ans = ans.empty() ? "0" : ans;
    }
};

// Time Complexity : O(n) + O(k)
// Space Complexity: O(n)  