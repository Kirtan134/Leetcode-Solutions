class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int minFreq = n, maxFreq = 1;
                for(int k=0;k<26;k++){
                    if(freq[k]){
                        minFreq=min(minFreq,freq[k]);
                        maxFreq=max(maxFreq,freq[k]);
                    }
                }
                ans+=(maxFreq-minFreq);
            }
        }
        return ans;
    }
};