class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long reversed = 0, temp = x;
        while(temp!=0){
            reversed = reversed*10 + temp%10;
            temp/=10;
        }
        return reversed == x;
    }
};