class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), i = n-1, c = 0;
        while(i>=0 && s[i]==32) i--;
        while(i>=0 && s[i]!=32){
            c++; i--;
        }
        return c;
    }
};