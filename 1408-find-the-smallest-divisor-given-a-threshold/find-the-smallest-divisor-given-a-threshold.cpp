class Solution {
private:
    int solve(vector<int>& nums, int mid, int n){
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=ceil((double)nums[i]/(double)mid);
        }
        return ans;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low=1, high= *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            int ans = solve(nums,mid,n);
            if(ans>threshold) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};