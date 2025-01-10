class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0, bit, remainder, diff;
        for(int i=0;i<32;i++){
            bit = (left>>i)&1;
            if(!bit) continue;

            remainder = left % (1 << (i+1));
            diff = (1LL<<(i+1)) - remainder;

            if(right-left<diff){
                ans |= (1<<i);
            }
        }
        return ans;
    }
};