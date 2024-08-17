class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, c;
        for(int i=0;i<32;i++){
            c=0;
            for(int j=0;j<n;j++){
                if(nums[j] & (1<<i)) c++;
            }
            if(c%3!=0){
                ans |= (1<<i);
            }
        }
        return ans;
    }
};