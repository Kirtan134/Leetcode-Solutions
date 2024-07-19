class Solution {
private:
    int solve(int mid, vector<int>& nums){
        int temp=0, ans=1;
        for(int i=0;i<nums.size();i++){
            if(temp+nums[i]<=mid){
                temp+=nums[i];
            }
            else{
                temp=nums[i];
                ans++;
            }
        }
        return ans;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int ans = solve(mid,nums);
            if(ans>k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
}; 