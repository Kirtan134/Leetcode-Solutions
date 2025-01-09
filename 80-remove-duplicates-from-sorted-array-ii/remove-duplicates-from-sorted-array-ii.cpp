class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), i=0, j=0, c=0;
        while(j<n){
            c=1;
            while((j+1)<n && nums[j]==nums[j+1]){
                j++; c++;
            }
            for(int k=0;k<min(2,c);k++){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};