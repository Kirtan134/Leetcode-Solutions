class Solution {
private:
    int solve(vector<int>& nums, int mid){
        int c=0, days=1;
        for(int i=0;i<nums.size();i++){
            if(c<mid && c+nums[i]<=mid){
                c+=nums[i];
            }
            else{
                if(c<=mid) days++;
                c=nums[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low<=high){
            int mid = (low+high)/2;
            int ans = solve(weights,mid);
            if(ans > days) low=mid+1;
            else high = mid-1;
        }
        return low;
    }
};