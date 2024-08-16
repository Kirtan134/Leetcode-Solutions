// Most Optimal Solution
// Time: O(n)
// Space: O(1) 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0, twos=0;
        for(int i=0;i<nums.size();i++){
            // add in ones if not in twos
            ones = (ones^nums[i]) & ~twos;
            // add in twos if not in ones
            twos = (twos^nums[i]) & ~ones;
            // add in threes if not in twos (not needed)
        }
        return ones;
    }
};