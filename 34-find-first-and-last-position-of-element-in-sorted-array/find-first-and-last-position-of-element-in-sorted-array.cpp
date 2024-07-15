class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0,high=n-1;
        vector<int> ans;
        int temp=-1;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                temp = mid;
                high= mid-1;
            }
            else if(target<nums[mid]){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        ans.push_back(temp);
        low=0,high=n-1,temp=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                temp = mid;
                low=mid+1;
            }
            else if(target<nums[mid]){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        ans.push_back(temp);
        // if(ans.empty()){
        //     ans.push_back(-1);
        //     ans.push_back(-1);
        // }
        return ans;
    }
};