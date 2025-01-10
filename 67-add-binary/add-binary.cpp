class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0, i = a.size()-1, j = b.size()-1;

        while(i>=0 || j>=0 || carry>0){
            int A = i>=0 ? a[i] - '0' : 0;
            int B = j>=0 ? b[j] - '0' : 0;

            int total = A + B + carry;
            ans += (total%2) + '0';
            carry = total/2;

            i--; j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};